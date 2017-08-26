#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int cnt[256];

int main() {
  scanf("%s", s);
  memset(cnt, 0, sizeof cnt);
  int n = strlen(s);
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    for (char c = 'a'; c <= 'z'; c++)
      if (c != s[i])
        ans += cnt[c];
    cnt[s[i]]++;
  }
  cout << ans << endl;
  return 0;
}