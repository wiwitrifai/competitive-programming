#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  vector<string> s(k);
  string tmp;
  for (int i = 0; i < k; ++i) {
    cin >> s[i] >> tmp;
    s[i].push_back(tmp[1]);
    s[i].push_back(tmp[0]);
  }
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  auto smallest = [&](string p) {
    string ans = p;
    for (int i = 1; i < 4; ++i) {
      string cur = p.substr(i, 4-i) + p.substr(0, i);
      assert(cur.size() == 4);
      if (cur < ans)
        ans = cur;
    }
    return ans;
  };
  map<string, int> cnt;
  for (auto & p : s) {
    p = smallest(p);
    ++cnt[p];
  }
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; j += 2) {
      string cur;
      cur.push_back(grid[i][j]);
      cur.push_back(grid[i][j+1]);
      cur.push_back(grid[i+1][j+1]);
      cur.push_back(grid[i+1][j]);
      cur = smallest(cur);
      auto it = cnt.find(cur);
      if (it == cnt.end() || it->second <= 0) {
        cout << "No\n";
        return 0;
      }
      it->second--;
    }
  }
  cout << "Yes\n";
  return 0;
}
