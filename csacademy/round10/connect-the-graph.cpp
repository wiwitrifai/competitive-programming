#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N];
pair<int, int> del[N];

int root(int x) {
  return p[x] < 0 ? x : p[x] = root(p[x]);
}

bool merge(int u, int v) {
  if ((u = root(u)) == (v = root(v)))
    return false;
  if (p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(p, -1, sizeof p);
  int d = 0;
  int cnt = n;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (!merge(u, v)) {
      del[d++] = {u, v};
    }
    else
      cnt--;
  }
  if (cnt-1 > d) {
    puts("-1");
    return 0;
  } 
  printf("%d\n", cnt-1);
  for (int i = 1; i < n; i++) {
    if (merge(i, i+1)) {
      d--;
      printf("%d %d %d %d\n", del[d].first, del[d].second, i, i+1);
    }
  }

  return 0;
}