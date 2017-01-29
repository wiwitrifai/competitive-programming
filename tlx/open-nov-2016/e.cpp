#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];
bitset < N > bs;

int main() {
  bs.set();
  bs[0] = bs[1] = 0;
  for (int i = 2; i < N; i++) if (bs[i]) {
    for (long long j = 1LL * i  *i; j < N; j += i)
      bs[j] = 0;
  }
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int prime = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (bs[a[i]]) {
      if (prime == -1)
        prime = a[i];
    }
    else {
      if (k >= a[i]) {
        ans++;
        k -= a[i];
      }
    }
  }
  if (prime > 0 && k >= prime) {
    k -= prime;
    ans++;
  }
  if (ans == n)
    puts("One Punch!");
  else
    printf("%d\n", ans);
  return 0;
}