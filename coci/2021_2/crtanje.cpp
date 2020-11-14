#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int now = 0, low = 0, hig = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      ++now;
    } else if (s[i] == '-') {
      --now;
    }
    low = min(low, now);
    hig = max(hig, now);
  }
  vector<string> ans(hig - low + 1, string(n, '.'));
  now = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      ans[now - low][i] = '/';
      ++now;
    } else if (s[i] == '-') {
      --now;
      ans[now - low][i] = '\\';
    } else {
      ans[now - low][i] = '_';
    }
  }
  for (int i = (int)ans.size()-1; i >= 0; --i) {
    if (ans[i] == string(n, '.'))
      continue;
    cout << ans[i] << '\n';
  }
  return 0;
}
