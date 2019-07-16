// Accepted
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 6, mod = 1e9 + 7;

int a[N], off[N], to[N];
int sa[N], pos[N], tmp[N], gap, m;

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < m && b < m) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  for(int i = 0; i<m; i++)
    sa[i] = i, pos[i] = a[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + m, cmp_sa);
    for(int i = 1; i<m; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<m; i++) pos[sa[i]] = tmp[i];
    if(tmp[m-1] == m-1) break;
  }
}


int main() {
  int n;
  m = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int s;
    scanf("%d", &s);
    off[i] = m;
    while (s--) {
      scanf("%d", a+m++);
    }
    to[i] = m;
    a[m++] = 356;
  }
  a[m++] = 357;
  build_sa();
  priority_queue<pair<int, int> > pq;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    pq.emplace(-pos[off[i]], i);
  }
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    int id = it.second;
    ans = 1LL * (ans + a[off[id]]) * 365 % mod;
    if (off[id]+1 < to[id])
      pq.emplace(-pos[++off[id]], id);
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}