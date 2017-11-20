#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int cnt[256], cur[256];

string s[N];

int main() {
  // sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cnt[s[i][0]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(cur, 0, sizeof cur);
    for (int j = 0; j < s[i].size(); j++)
      cur[s[i][j]]++;
    bool ok = 1;
    for (int j = 'a'; j <= 'z'; j++)
      ok &= cur[j] <= cnt[j];
    ans += ok;
  }
  printf("%d\n", ans);
  return 0;
}