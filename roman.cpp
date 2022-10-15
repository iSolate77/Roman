#include <cctype>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

std::string getRoman(int);

int main() {
  int n;
  while (true) {
    std::cout << "Type a number: ";
    if (std::cin >> n) {
      break;
    } else {
      std::cout << "Please enter a valid number." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  std::cout << "You entered: " << n << std::endl;
  std::cout << "In Roman numerals: " << getRoman(n) << std::endl;

  return EXIT_SUCCESS;
}

std::string getRoman(int x) {
  std::string roman = "";
  while (x != 0) {
    if (x < 5000 && x > 4000) {
      if (x / 1000 == 4) {
        roman.append("_I_V");
        x = x % 1000;
      }
    } else if (x < 4000 && x > 1000) {
      for (int i = 0; i < x / 1000; i++) {
        roman.append("M");
      }
      x = x % 1000;
    } else if (x < 1000 && x >= 100) {
      if (x / 100 == 9) {
        roman.append("CM");
        x = x % 100;
      } else if ((x / 100) >= 5) {
        roman.append("D");
        for (int i = 0; i < (x / 100) - 5; i++) {
          roman.append("C");
        }
        x = x % 100;
      } else if (x / 100 == 4) {
        roman.append("CD");
        x = x % 100;
      } else {
        for (int i = 0; i < x / 100; i++) {
          roman.append("C");
        }
        x = x % 100;
      }
    } else if (x < 100 && x >= 10) {
      if (x / 10 == 9) {
        roman.append("XC");
        x = x % 10;
      } else if (x / 10 >= 5) {
        roman.append("L");
        for (int i = 0; i < (x / 10) - 5; i++) {
          roman.append("X");
        }
        x = x % 10;
      } else if (x / 10 == 4) {
        roman.append("XL");
        x = x % 10;
      } else {
        for (int i = 0; i < x / 10; i++) {
          roman.append("X");
        }
        x = x % 10;
      }
    } else {
      if (x < 10 && x > 0) {
        if (x == 9) {
          roman.append("IX");
          x = 0;
        } else if (x >= 5) {
          roman.append("V");
          for (int i = 0; i < x - 5; i++) {
            roman.append("I");
          }
          x = 0;
        } else if (x == 4) {
          roman.append("IV");
          x = x;
        } else {
          for (int i = 0; i < x; i++) {
            roman.append("I");
          }
          x = 0;
        }
      }
    }
  }
  return roman;
};
