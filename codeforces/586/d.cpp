#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];
int cnt[60];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    ++cnt[__builtin_ctzll(a[i])];
  }
  int best = 0;
  for (int i = 0; i < 60; ++i)
    if (cnt[best] < cnt[i])
      best = i;
  printf("%d\n", n - cnt[best]);
  for (int i = 0; i < n; ++i) {
    if (__builtin_ctzll(a[i]) == best) continue;
    printf("%lld ", a[i]);
  }
  printf("\n");
  return 0;
}
