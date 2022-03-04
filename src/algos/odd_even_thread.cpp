#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>

int main(int argc, char **argv) {

  int count = 1;
  std::condition_variable cond;
  std::mutex oe_mutex;

  auto func = [&count, &cond, &oe_mutex] (int n, bool odd) {
    while (count < n) {
      std::unique_lock<std::mutex> ulock(oe_mutex);
      cond.wait(
          ulock,
          [&count, &odd](){
            return (count % 2 != 0 && odd) || (count % 2 == 0 && !odd);
          });
      std::cout << count << std::endl;
      count++;
      cond.notify_all();
    }
  };

  std::thread othread(func, 10, true);
  std::thread ethread(func, 10, false);
  othread.join();
  ethread.join();

  return 0;
}
