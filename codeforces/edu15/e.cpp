#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long k;
int w[N], f[N], cur[N], anw[N], tw[N], tf[N];
long long s[N], ans[N], ts[N];

int main() {
  scanf("%d%I64d", &n, &k);
  for(int i = 0; i<n; i++)
    scanf("%d", f+i), cur[i] = i;
  for(int i = 0; i<n; i++) {
    scanf("%d", w+i);
    anw[i] = 1e9+7;
    s[i] = w[i];
    ans[i] = 0;
  }
  for(long long mask = 1; mask <= k; mask <<= 1) {
    if(mask & k) {
      for(int i = 0; i<n; i++) {
        ans[i] += s[cur[i]];
        anw[i] = min(anw[i], w[cur[i]]);
        cur[i] = f[cur[i]];
      }
    }
    for(int i = 0; i<n; i++) {
      tw[i] = min(w[i], w[f[i]]);
      ts[i] = s[i] + s[f[i]];
      tf[i] = f[f[i]];
    }
    for(int i = 0; i<n; i++) {
      w[i] = tw[i];
      s[i] = ts[i];
      f[i] = tf[i];
    }
  }
  for(int i = 0; i<n; i++) {
    printf("%I64d %d\n", ans[i], anw[i]);
  }

  return 0;
}