#pragma once

namespace bits {
namespace benchmark {
  class BitTwidling {
    public:
      BitTwidling();

      // Compute Sign Functions
      int computeSignBranching(const int& num);
      int computeSignNoBranching(int num);
      int computeSignThree(int num);

      // Detect if two integers have opposite signs
      bool checkOppositeSigns(const int& x, const int& y);

      // Conpute abs without branching
      unsigned int computeAbs(const int& num);
  };
}

}

/*----------- Templated Implementation ------------

namespace bits {

  namespace benchmark {

    template <typename T>
      BitTwidling<T>::BitTwidling() {

      }

    template <typename T>
      int BitTwidling<T>::computeSignBranching(const T& num) {
        return -(num < 0);
      }

    template <typename T>
      int BitTwidling<T>::computeSignNoBranching(T num) {
        // Additional instruction but portable
        // return -(int)((unsigned int)((int) num) >> (sizeof(T) * CHAR_BIT - 1));
        // One less instruction but less portable
        return num >> (sizeof(T) * CHAR_BIT - 1);
      }

    template <typename T>
      int BitTwidling<T>::computeSignThree(T num) {
        // return (num != 0) | -(int)((unsigned int)((int) num) >> (sizeof(T) * CHAR_BIT - 1));
        // For portability, brevity and (perhaps) speed
        return (num > 0) - (num < 0);
      }

    template <typename T>
      bool BitTwidling<T>::checkOppositeSigns(const T& x, const T& y) {
        return ((x ^ y) < 0);
      }

    template <typename T>
      unsigned T computeAbs(const T& num) {
        T const mask = num >> sizeof(T) * CHAR_BIT - 1;

        // patented??
        // return (num ^ mask) - mask;
        return (num + mask) ^ mask;
      }
  }
}

----------------------------------------------------*/
