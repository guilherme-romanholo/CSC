#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

std::string decToBin(long int num);
std::string decToHex(long int num);
long int binToDec(long int num);
long int hexToDec(std::string num);

int main(int argc, char *argv[]) {
  int N;
  long int num;
  std::string input1, input2;
  std::stringstream ss;

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> input1 >> input2;
    if (input2 == "dec") {
      ss << input1;
      ss >> num;
      std::cout << "Case " << i + 1 << ":" << std::endl;
      std::cout << decToHex(num) << " hex" << std::endl;
      std::cout << decToBin(num) << " bin" << std::endl;
    } else if (input2 == "bin") {
      ss << input1;
      ss >> num;
      std::cout << "Case " << i + 1 << ":" << std::endl;
      std::cout << binToDec(num) << " dec" << std::endl;
      std::cout << decToHex(binToDec(num)) << " hex" << std::endl;
    } else {
      std::cout << "Case " << i + 1 << ":" << std::endl;
      std::cout << hexToDec(input1) << " dec" << std::endl;
      std::cout << decToBin(hexToDec(input1)) << " bin" << std::endl;
    }
  }
  return 0;
}

long int hexToDec(std::string num) {
  long int dec = 0;
  for (int i = num.size() - 1, j = 0; i >= 0; i--, j++) {
    switch (num[j]) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
      dec += (num[j] - 87) * pow(16, i);
      break;
    default:
      dec += (num[j] - '0') * pow(16, i);
      break;
    }
  }
  return dec;
}

long int binToDec(long int num) {
  long int dec = 0, i = 0;
  while (num) {
    dec += num % 10 * pow(2, i);
    num = num / 10;
    i++;
  }
  return dec;
}

std::string decToBin(long int num) {
  std::string binario;
  if (num == 0)
    binario.push_back('0');
  while (num) {
    binario.push_back(num % 2 + '0');
    num = num / 2;
  }
  std::reverse(binario.begin(), binario.end());
  return binario;
}

std::string decToHex(long int num) {
  std::string hex;
  if (num == 0)
    hex.push_back('0');
  while (num) {
    switch (num % 16) {
    case 10:
      hex.push_back('a');
      break;
    case 11:
      hex.push_back('b');
      break;
    case 12:
      hex.push_back('c');
      break;
    case 13:
      hex.push_back('d');
      break;
    case 14:
      hex.push_back('e');
      break;
    case 15:
      hex.push_back('f');
      break;
    default:
      hex.push_back(num % 16 + '0');
      break;
    }
    num = num / 16;
  }
  std::reverse(hex.begin(), hex.end());
  return hex;
}
