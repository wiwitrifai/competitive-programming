#include <bits/stdc++.h>

using namespace std;

const int N = 404;

char s[N][N];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  vector<pair<int, int>> ans;
  if (s[0][1] == s[1][0]) {
    if (s[n-1][n-2] == s[0][1]) {
      ans.emplace_back(n-1, n-2);
    }
    if (s[n-2][n-1] == s[0][1]) {
      ans.emplace_back(n-2, n-1);
    }
  } else if (s[n-1][n-2] == s[n-2][n-1]) {
    if (s[n-1][n-2] == s[0][1]) {
      ans.emplace_back(0, 1);
    }
    if (s[n-1][n-2] == s[1][0]) {
      ans.emplace_back(1, 0);
    }
  } else {
    ans.emplace_back(1, 0);
    if (s[n-1][n-2] == s[0][1]) {
      ans.emplace_back(n-1, n-2);
    }
    if (s[n-2][n-1] == s[0][1]) {
      ans.emplace_back(n-2, n-1);
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    printf("%d %d\n", it.first + 1, it.second+1);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
