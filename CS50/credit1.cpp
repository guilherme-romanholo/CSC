#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  string card;
  int sum = 0;
  cin >> card;
  for (int i = 0; card[i] != '\0'; i++) {
    sum += card[i] - '0';
  }
  cout << sum << endl;
  return 0;
}
