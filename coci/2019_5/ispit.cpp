#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N][N];
int cnt[26];
int n, k;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int l = 0, r = n;
      while (l < n && s[i][l] == s[j][l]) ++l;
      while (r >= l && s[i][r] == s[j][r]) --r;
      if (r-l+1 > k) continue;
      memset(cnt, 0, sizeof cnt);
      for (int z = l; z <= r; ++z) {
        ++cnt[s[i][z] - 'a'];
        --cnt[s[j][z] - 'a'];
      }
      bool ok = 1;
      for (int z = 0; z < 26; ++z)
        ok &= cnt[z] == 0;
      if (ok) {
        puts("DA");
        return 0;
      }
    }
  }
  puts("NE");
  return 0;
}