// can you hack wifi? :p
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
vector<pair<int, int> > g[N];
long long flow[N << 2], pipa[N << 2], initf[N];
int n, m, q;

void combine(int id) {
  int il = id << 1, ir = il | 1;
  long long r = min(pipa[il], flow[ir]);
  flow[id] = flow[il] + r;
  pipa[id] = min(pipa[il]-r, pipa[ir]);
}

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    flow[id] = initf[l];
    pipa[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  combine(id);
}

void update(int v, int w, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    pipa[id] = w;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (v < mid)
    update(v, w, il, l, mid);
  else
    update(v, w, ir, mid, r);
  combine(id);
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d %d", a+i, b+i);
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    g[v].emplace_back(u, w);
  }
  a[n-1] = b[n-1] = 0;
  map<int, long long> mp;
  long long curflow = 0;
  for (int i = 0; i < n; ++i) {
    for (auto it : g[i]) {
      mp[-it.first] += it.second;
      curflow += it.second;
    }
    if (i == n-1) continue;
    long long rem = max(0LL, curflow-b[i]);
    curflow -= rem;
    auto it = mp.begin();
    while (rem > 0) {
      if (it->second <= rem) {
        rem -= it->second;
        it = mp.erase(it);
      }
      else
        it->second -= rem, rem = 0;
    }
  }
  for (auto it : mp) {
    initf[-it.first] = it.second;
  }
  build();
  printf("%I64d\n", flow[1]);
  while (q--) {
    int v, w;
    scanf("%d %d", &v, &w);
    v--;
    update(v, w);
    printf("%I64d\n", flow[1]);
  }
  return 0;
}