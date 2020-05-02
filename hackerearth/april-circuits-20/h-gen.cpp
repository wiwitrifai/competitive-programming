#include <bits/stdc++.h>

using namespace std;

const int W = 1e4;

int main() {
  set<pair<int,int>> edges;
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  printf("%d %d %d\n", n, m, k);
  int s = rand() % n;
  int t = rand() % n;
  while (t == s)
    t = rand() % n;
  printf("%d %d\n", s+1, t+1);
  for (int i = 1; i < n; ++i) {
    int par = rand() % i;
    printf("%d %d %d\n", par+1, i+1, 1 + (rand() % W));
    edges.insert(make_pair(par, i));
  }
  m -= n-1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    do {
      u = rand() % n;
      v = rand() % n;
      if (u > v)
        swap(u, v);
    } while (u == v || edges.count(make_pair(u, v)));
    printf("%d %d %d\n", u+1, v+1, 1 + (rand() % W));
  }
  set<int> bk;
  bk.insert(s);
  bk.insert(t);
  while ((int)bk.size() < n - k) {
    bk.insert(rand() % n);
  }
  for (int i = 0; i < n; ++i) {
    if (bk.count(i)) continue;
    printf("%d ", i+1);
  }
  printf("\n");
  return 0;
}
