#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N], c[N];

pair<int, int> find(int x) {
  if (p[x] < 0)
    return make_pair(x, 0);
  pair<int, int> res = find(p[x]);
  c[x] ^= res.second;
  p[x] = res.first;
  return make_pair(res.first, c[x]);
}

bool merge(int u, int v) {
  pair<int, int> pu = find(u), pv = find(v);
  if (pu.first == pv.first && pu.second == pv.second)
    return 0;
  if (pu.first == pv.first)
    return 1;
  u = pu.first, v = pv.first;
  c[u] ^= (pu.second == pv.second);
  p[u] = v;
  return 1;
}

int main() {
  memset(p, -1, sizeof p);
  int n;
  scanf("%d", &n);
  while (1) {
    int a, b;
    scanf("%d %d", &a, &b);
    int res = merge(a, b);
    printf("%d\n", res);
    fflush(stdout);
    if (res == 0) {
      break;
    }
  }
  return 0;
}