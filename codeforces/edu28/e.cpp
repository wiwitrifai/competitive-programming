#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
long long a[N], b[N];
vector<pair<int, int>> g[N];

int sign(long long x) {
  return (x > 0) - (x < 0);
}

long long mul(long long le, long long ri) {
  if (le == 0)
    return 0;
  int sgn = sign(le) * sign(ri);
  le = abs(le);
  ri = abs(ri);
  if (inf / le < ri)
    return sgn * inf;
  return le * ri * sgn;
}
long long add(long long le, long long ri) {
  long long val = le + ri;
  if (val < -inf)
    return -inf;
  if (val > inf)
    return inf;
  return val;
}

bool ans = 1;

long long dfs(int v, int k = 1) {
  for (auto it : g[v]) {
    b[v] = add(b[v], dfs(it.first, it.second));
  }
  if (b[v] <= -inf)
    ans = 0;
  if (b[v] >= a[v]) {
    return b[v] - a[v];
  }
  long long need = add(a[v], -b[v]);
  if (need >= inf)
    ans = 0;
  need = mul(need, k);
  if (need >= inf)
    ans = 0;
  return -need;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%I64d", b+i);
  for (int i = 0; i < n; i++)
    scanf("%I64d", a+i);
  for (int i = 1; i < n; i++) {
    int p, k;
    scanf("%d %d", &p, &k);
    p--;
    g[p].emplace_back(i, k);
  }
  ans = 1;
  ans &= dfs(0) >= 0;
  puts(ans ? "YES" : "NO");
  return 0;
}