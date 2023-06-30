#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
  map<int, string> convert = {{1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},
                              {10, "X"},  {40, "XL"},  {50, "L"},  {90, "XC"},
                              {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
                              {1000, "M"}};
  int num[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}, input,
      i = 0;

  cin >> input;

  while (input != 0) {
    if (input - num[i] >= 0) {
      input -= num[i];
      cout << convert[num[i]];
    } else {
      i++;
    }
  }
  cout << "\n";
  return 0;
}
