#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], c[N], p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

int main() {
  memset(p, -1, sizeof p);
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  int cnt = n;
  int tot = 0;
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d", a+i, b+i, c+i);
    if (c[i] == 0) {
      tot += merge(a[i], b[i]);
    }
  }
  cnt -= tot;
  set<int> st;
  for (int i = 0;i < q; ++i) {
    if (c[i]) {
      if (find(a[i]) == find(b[i])) {
        puts("No");
        return 0;
      }
      st.insert(find(a[i]));
      st.insert(find(b[i]));
    }
  }
  long long mini = tot + (int)st.size();
  long long maxi = tot + 1LL * cnt * (cnt - 1) / 2;
  puts((mini <= m && m <= maxi) ? "Yes" : "No");
  return 0;
}
