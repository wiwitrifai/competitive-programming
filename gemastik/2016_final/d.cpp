#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

long long a[N], v[N], s[N];

int x[N], k[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(a, 0, sizeof a);
    memset(v, 0, sizeof v);
    memset(s, 0, sizeof s);
    for (int i = 0; i < m; i++) {
      scanf("%d %d", x+i, k+i);
      v[x[i]] += k[i];
      if (x[i]+1 <= n)  
        a[x[i]+1]--;
      if (x[i]+k[i]+1 <= n)
        a[x[i]+k[i]+1]++;
    }
    long long vv = 0, snow = 0;
    for (int i = 1; i <= n; i++) {
      vv += a[i];
      snow += v[i] + vv;
      s[i] = snow;
    }
    vv = 0;
    memset(a, 0, sizeof a);
    memset(v, 0, sizeof v);
    for (int i = 0; i < m; i++) {
      s[x[i]] -= k[i];
      v[x[i]] += k[i];
      if (x[i] >= 1)
        a[x[i]-1]--;
      if (x[i]-k[i]-1 >= 0)
        a[x[i]-k[i]-1]++;
    }
    vv = 0;
    snow = 0;
    for (int i = n; i > 0; i--) {
      vv += a[i];
      snow += v[i] + vv;
      s[i] += snow;
    }
    for (int i = 1; i <= n; i++) {
      printf("%lld%c", s[i], i == n ? '\n' : ' ');
    }
  }
  return 0;
}