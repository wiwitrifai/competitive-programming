#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], to[N];

int state[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i) {
    scanf("%d", to+i);
    --to[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (state[i]) continue;
    int now = i;
    while (state[now] == 0) {
      state[now] = 1;
      now = to[now];
    }
    if (state[now] == 1) {
      int mi = a[now];
      while (state[now] == 1) {
        state[now] = 2;
        mi = min(mi, a[now]);
        now = to[now];
      }
      ans += mi;
    }
    now = i;
    while (state[now] == 1) {
      state[now] = 2;
      now = to[now];
    }
  }
  printf("%lld\n", ans);
  return 0;
}