#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n) {
  vector<string> resp;

  for (int i = 1; i <= n; i++) {
    if (!(i % 3) && !(i % 5))
      resp.push_back("FizzBuzz");
    else if (!(i % 3) && i % 5)
      resp.push_back("Fizz");
    else if (i % 3 && !(i % 5))
      resp.push_back("Buzz");
    else 
      resp.push_back(to_string(i));
  }

  return resp;
}

int main(int argc, char *argv[]) {
  int num;
  vector<string> teste;

  cin >> num;
  teste = fizzBuzz(num);

  for (string i : teste)
    cout << i << " ";
  cout << endl;

  return 0;
}
