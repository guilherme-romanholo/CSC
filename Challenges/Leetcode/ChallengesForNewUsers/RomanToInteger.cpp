#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s) {
  int resp = 0;
  map<char, int> conversionTable{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                 {'C', 100}, {'D', 500}, {'M', 1000}};

  for (int i = 0; i < s.size(); i++) {
    if (conversionTable[s[i]] >= conversionTable[s[i + 1]]) {
      resp += conversionTable[s[i]];
    } else {
      resp += conversionTable[s[i + 1]] - conversionTable[s[i]];
      i++;
    }
  }

  return resp;
}

int main(int argc, char *argv[]) {
  string roman;
  cin >> roman;

  cout << "Int: " << romanToInt(roman) << "\n";

  return 0;
}
