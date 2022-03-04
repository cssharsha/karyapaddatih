#include <climits>

#include "algos/bit_twidling.hpp"

namespace bits {
  namespace benchmark {

    BitTwidling::BitTwidling() {

    }

    int BitTwidling::computeSignBranching(const int& num) {
      return -(num < 0);
    }

    int BitTwidling::computeSignNoBranching(int num) {
      // Additional instruction but portable
      // return -(int)((unsigned int)((int) num) >> (sizeof(T) * CHAR_BIT - 1));
      // One less instruction but less portable
      return num >> (sizeof(int) * CHAR_BIT - 1);
    }

    int BitTwidling::computeSignThree(int num) {
      // return (num != 0) | -(int)((unsigned int)((int) num) >> (sizeof(T) * CHAR_BIT - 1));
      // For portability, brevity and (perhaps) speed
      return (num > 0) - (num < 0);
    }

    bool BitTwidling::checkOppositeSigns(const int& x, const int& y) {
      return ((x ^ y) < 0);
    }

    unsigned int BitTwidling::computeAbs(const int& num) {
      int const mask = num >> sizeof(int) * CHAR_BIT - 1;

      // patented??
      // return (num ^ mask) - mask;
      return (num + mask) ^ mask;
    }
  }
}
