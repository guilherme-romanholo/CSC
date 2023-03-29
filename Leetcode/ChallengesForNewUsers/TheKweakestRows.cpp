#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
  vector<int> ans;
  set<pair<int, int>> rows;
  int count = 0;

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      if (mat[i][j] == 1) {
        count++;
      }
    }
    rows.insert(make_pair(count, i));
    count = 0;
  }

  for (auto var : rows) {
    ans.push_back(var.second);
  }

  ans.erase(ans.begin() + k, ans.end());

  return ans;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> mat;
  vector<int> ans, aux;
  int n, m, k, e;

  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> e;
      aux.push_back(e);
    }
    mat.push_back(aux);
    aux.clear();
  }

  ans = kWeakestRows(mat, k);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
