#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<int> vx;
int n, a[N], b[N];
int p[N + N], e[N + N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  e[u] += e[v];
  p[u] += p[v];
  p[v] = u;
}

bool can(int x) {
  fill(e, e+x+1, 0);
  fill(p, p+x+1, -1);
  for (int i = 0; i < n; ++i) {
    if (b[i] <= x)
      merge(a[i], b[i]);
    ++e[find(a[i])];
  }
  for (int i = 0; i <= x; ++i) {
    if (p[i] >= 0) continue;
    if (-p[i] < e[i]) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
    vx.push_back(a[i]);
    vx.push_back(b[i]);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin();
    b[i] = lower_bound(vx.begin(), vx.end(), b[i]) - vx.begin();
  }
  int lo = 0, hi = vx.size();
  for (int i = 0; i < n; ++i)
    lo = max(lo, a[i]);
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (can(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%d\n", (lo >= vx.size()) ? -1 : vx[lo]);
  return 0;
}