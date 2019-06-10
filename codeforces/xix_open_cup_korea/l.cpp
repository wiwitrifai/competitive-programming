#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[N], bad[N], a[N];

int up[N], down[N];
int go[N];
int n;
pair<int, int> calc(int x) {
  if (cnt[x] != -1)
    return {cnt[x], bad[x]};
  cnt[x] = 0;
  bad[x] = 0;
  int now = 0;
  while (now < n) {
    int add = min(n - now, max(x, go[now]));
    ++cnt[x];
    bad[x] += add - go[now];
    now += add;
  }
  return {cnt[x], bad[x]};
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  up[n-1] = down[n-1] = go[n-1] = 1;
  for (int i = n-2; i >= 0; --i) {
    if (a[i+1] >= a[i]) {
      up[i] = up[i+1] + 1;
      down[i] = 1;
      go[i] = up[i];
    }
    else {
      up[i] = 1;
      down[i] = down[i+1] + 1;
      go[i] = down[i];
    }
  }
  memset(cnt, -1, sizeof cnt);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d %d\n", calc(x).first, calc(x).second);
  }
  return 0;
}
