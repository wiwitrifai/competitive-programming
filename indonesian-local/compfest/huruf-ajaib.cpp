#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
char s[N], ss[N];
int to[N][26];
int t, m, n;
long long k, x;
long long sum[N];
long long get(long long y) {
  return sum[n] * (y/n) + sum[y % n];
}


int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    n = strlen(s);
    scanf("%d %lld %lld", &m, &k, &x);
    sum[0] = 0;
    char mc = s[0]-'a';
    for (int i = 0; i < n; ++i)
      s[i] -= 'a', mc = min(mc, s[i]);
    for (int i = 0; i < n; i++)
      sum[i+1] = sum[i] + (s[i] == mc);
    long long all = 1LL * n * m;
    long long le = 0, ri = all;
    while (le < ri) {
      long long mid = (le + ri + 1) / 2;
      if (k - get(mid) <= all - mid)
        le = mid;
      else
        ri = mid - 1;
    }
    if (get(le) >= x)
      printf("%c\n", mc + 'a');
    else {
      k -= get(le);
      x -= get(le);
      le--;
      while (le >= 0 && s[le % n] != mc) le--;
      ri = le + 1;
      while (ri < all && s[ri % n] != mc) ri++;
      if (all - ri >= k-x+1) {
        long long rev = (k-x) % n;
        printf("%c\n", s[n-1-rev] + 'a');
      }
      else {
        k -= all-ri;
        int nn = 0;
        for (long long i = le+1; i < ri; i++) {
          ss[nn++] = s[i % n];
        }
        assert(x <= nn && x > 0 );
        for (int i = 0; i < 26; i++)
          to[nn][i] = nn;
        for (int i = nn-1; i >= 0; i--) {
          for (int j = 0; j < 26; j++)
            to[i][j] = to[i+1][j];
          to[i][ss[i]] = i;
        }
        int now = 0;
        while (x--) {
          k--;
          bool found = 0;
          for (int i = 0; i < 26; i++) {
            int sisa = nn-1-to[now][i];
            if (sisa >= k) {
              now = to[now][i]+1;
              found = 1;
              break;
            }
          }
          assert(found);
        }
        printf("%c\n", ss[now-1] + 'a');
      }
    }
  }
  return 0;
}