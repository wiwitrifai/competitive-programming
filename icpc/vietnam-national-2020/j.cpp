#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> h, hig;
long long solve(int id, int cnt) {
  if (id == n) {
    if (cnt != 0)
      return 0;
    int now = 0;
    for (int i = 0; i < n; ++i) {
      hig[i] = now;
      now = max(now, h[i]);
    }
    now = 0;
    long long ret = 0;
    for (int i = n-1; i >= 0; --i) {
      ret += max(0, min(hig[i], now) - h[i]);
      now = max(now, h[i]);
    }
    return ret;
  }
  long long ret = solve(id+1, cnt);
  if (cnt > 0) {
    ++h[id];
    ret = max(ret, solve(id, cnt-1));
    --h[id];
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &k);
  h.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
  hig.resize(n);
  printf("%lld\n", solve(0, k));
  return 0;
}
