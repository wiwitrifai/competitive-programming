#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = 102, mod = 1e9 + 9;

int a[N];
int cnt[N];
long long ar[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  long long ans = n+1;
  for (int d = -99; d < 100; d++) {
    memset(cnt, 0, sizeof cnt);
    memset(ar, 0, sizeof ar);
    for (int i = 0; i < n; i++) {
      if (a[i] - d >= 0 && a[i] - d < M) {
        ar[a[i]] += ar[a[i]-d];
        ar[a[i]] += cnt[a[i]-d];
        ar[a[i]] %= mod;
      }
      cnt[a[i]]++;
    }
    for (int i = 0; i < M; i++)
      ans = (ans + ar[i]) % mod; 
  }
  printf("%lld\n", ans);
  return 0;
}