#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 3, M = 2e5 + 5;

bool can[N];
char s[M];
int cnt[26];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d %s", &n, &m, &k, s);
    memset(cnt, 0, sizeof cnt);
    if (n > m)
      swap(n, m);
    for (int i = 0; i < k; ++i) {
      ++cnt[s[i]-'A'];
    }
    long long ans = 1LL * n * m;
    for (int i = 0; i < 26; ++i) {
      can[0] = 1;
      int sum = 0;
      for (int j = 0; j < 26; ++j) {
        if (i == j) continue;
        int now = cnt[j];
        sum = min(n, sum + now);
        for (int z = sum; z >= now; --z) {
          can[z] |= can[z-now];
        }
      }
      int all = k - cnt[i];
      for (int j = 0; j <= sum; ++j) {
        if (!can[j]) continue;
        int a = min(j, n), b = min(all - j, m);
        if (n + m - a - b > cnt[i]) continue;
        ans = min(1LL * (n - a) * (m - b), ans);
      }
      fill(can, can + sum+1, false);
    }
    printf("%lld\n", ans);
  }
  return 0;
}