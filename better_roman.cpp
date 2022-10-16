#include <iostream>
#include <limits>

std::string getRoman(int);

int main () {

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
  std::string roman_num [] = {"_M","_C_M", "_D", "_C_D", "_C", "_X_C", "_L", "_X_L", "_X", "_I_X", "_V", "_I_V", "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
  int values [] = {1000000, 900000, 500000, 400000, 100000, 90000, 50000, 40000, 10000, 9000, 5000, 4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  std::string result = "";

  for (int i = 0; i < 25; i++) {
    while (x - values[i] >= 0)
    {
      result += roman_num[i];
      x -= values[i];
    }
  }
  return result;
}
