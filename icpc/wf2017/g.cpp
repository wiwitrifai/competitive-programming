#include <bits/stdc++.h>

using namespace std;

const int N = 333;

char flip(char c) {
  if (c == '.') return '#';
  return '.';
}

vector<string> norm(const vector<string> & s) {
  int n = s.size(), m = s[0].size();
  int n1 = s.size(), n2 = 0, m1 = s[0].size(), m2 = 0;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < s[i].size(); ++j) {
      if (s[i][j] == '.') continue;
      n1 = min(n1, i);
      n2 = max(n2, i);
      m1 = min(m1, j);
      m2 = max(m2, j);
    }
  }
  vector<string> ret;
  for (int i = n1; i <= n2; ++i) {
    ret.push_back(s[i].substr(m1, m2-m1+1));
  }
  return ret;
}

vector<string> solve(const vector<string> & s) {
  int n = s.size(), m = s[0].size();
  if (n <= 2 || m <= 2)
    return s;
  vector<string> bef(n, string(m, '.'));
  vector<string> cur = s;
  for (int i = 1; i + 1 < n; ++i) {
    for (int j = 1; j + 1 < m; ++j) {
      if (cur[i-1][j-1] == '.') continue;
      bef[i][j] = '#';
      for (int a = -1; a <= 1; ++a) {
        for (int b = -1; b <= 1; ++b) {
          cur[i+a][j+b] = flip(cur[i+a][j+b]);
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cnt += cur[i][j] == '#';
  if (cnt <= 1) {
    return solve(norm(bef));
  }
  for (int i = n-2; i > 0; --i) {
    for (int j = 1; j + 1 < m; ++j) {
      if (cur[i+1][j-1] == '.') continue;
      bef[i][j] = flip(bef[i][j]);
      for (int a = -1; a <= 1; ++a) {
        for (int b = -1; b <= 1; ++b) {
          cur[i+a][j+b] = flip(cur[i+a][j+b]);
          if (cur[i+a][j+b] == '#') ++cnt;
          else --cnt;
        }
      }
    }
    if (cnt <= 1) {
      return solve(norm(bef));
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector<string> s;
  for (int i = 0; i < n; ++i) {
    string now;
    cin >> now;
    s.push_back(now);
  }
  vector<string> ans = norm(solve(s));
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << "\n";
  return 0;
}