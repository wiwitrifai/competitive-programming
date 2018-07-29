#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

bool cek(int x) {
  int last = -1;
  for (int i = 1; i <= n; ++i) {
    int cur = x - i;
    if (a[i] == cur) continue;
    if (last != -1 && last < i-1)
      return false;
    if (last != -1) {
      assert(last == i-1);
      if (cur == a[i-1])
        return false;
    }
    last = i;
  }
  if (last == -1 || x == n+1)
    return true;
  if (last < n || a[n] >= x-n-1)
    return false;
  return true;
}

int main() {
  scanf("%d", &n);
  int x = 0;
  long long tot = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    x = max(x, a[i]+i);
    tot += a[i];
  }
  assert(x >= n+1);
  while (!cek(x)) ++x;
  long long ans = 1LL * x * (x - 1) / 2 - tot;
  assert(ans >= 0);
  printf("%lld\n", ans);
  return 0;
}