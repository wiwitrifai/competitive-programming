#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N];

vector< int > e[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
  if ((x = find(x)) == (y = find(y)))
    return;
  if (p[x] > p[y])
    swap(x, y);
  p[x] += p[y];
  p[y] = x;
}
int cnt[N], a[N];
int  main() {
  memset(p, -1, sizeof p);
  int n, m, k;  
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    merge(u, v);
  }
  for (int i = 0; i < n; i++) {
    e[find(i)].push_back(i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int ma = 0;
    for (int u : e[i]) {
      cnt[a[u]]++;
      ma = max(ma, cnt[a[u]]);
    }
    // cerr << sum << " " << ma << endl;
    ans += e[i].size() - ma;
    for (int u : e[i]) {
      cnt[a[u]] = 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}