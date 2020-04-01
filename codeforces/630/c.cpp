#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int cnt[26];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i <= k-i-1; ++i) {
      memset(cnt, 0, sizeof cnt);
      for (int j = i; j < n; j += k) {
        ++cnt[s[j] - 'a'];
      }
      if (k-i-1 != i) {
        for (int j = k-i-1; j < n; j += k) {
          ++cnt[s[j] - 'a'];
        }
      }
      int tot = 0, maxi = 0;
      for (int j = 0; j < 26; ++j) {
        tot += cnt[j];
        maxi = max(maxi, cnt[j]);
      }
      ans += tot - maxi;
    }
    printf("%d\n", ans);
  }
  return 0;
}
