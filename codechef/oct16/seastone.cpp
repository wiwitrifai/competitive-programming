#include <bits/stdc++.h>

using namespace std;

const int N = 78787;

int a[N];
long long sum[N];
vector< int > fac[N];

int main() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      fac[j].push_back(i);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    sort(a, a+n);
    if ((m % n) == 0) {
      puts("0");
      continue;
    }
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
      sum[i+1] = sum[i] + a[i];
    }
    long long ans = sum[n-1];
    while (m > 0) {
      for (int i = 1; i <= n; i++) {
        int now = m;
        if ((m % i) == 0)
          ans = min(ans, sum[n-i] * i); 
        int h1 = now/i;
        now -= h1 * i;
        if (h1 * (n-i) < now)
          continue;
        int res = n-i;
        for (int j = 0, k = (int)fac[now].size() - 1; j < fac[now].size(); j++, k--) {
          if (fac[now][j] > res)
            break;
          if (fac[now][k] > h1)
            continue;
          int cur = fac[now][j];
          ans = min(ans, sum[n-i] * i + sum[n-i-cur] * cur);
        }
      }
      m -= n;
    }
    printf("%lld\n", ans);
  }
  return 0;
}