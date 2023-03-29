#include <cstdio>
#include <iostream>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
  int numVet[26]{0};

  for (int i = 0; i < magazine.size(); i++) {
    numVet[magazine[i] - 97]++;
  }
  for (int i = 0; i < ransomNote.size(); i++) {
    numVet[ransomNote[i] - 97]--;
  }
  for (int i = 0; i < 26; i++) {
    if (numVet[i] < 0)
      return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  string ransomNote, magazine;
  cin >> ransomNote >> magazine;

  if (canConstruct(ransomNote, magazine))
    cout << "true\n";
  else
    cout << "false\n";

  return 0;
}
