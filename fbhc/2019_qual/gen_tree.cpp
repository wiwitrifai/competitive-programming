#include <bits/stdc++.h>

using namespace std;

int rand_int(int l, int r) {
  return (rand() % (r - l + 1)) + l;
}

const int N = 212;

int par[N], tmp[N], lv[N];

void renumber(int n) {
  vector<int> node(n);
  for (int i = 0; i < n; ++i)
    node[i] = i;
  for (int i = 1; i <= n; ++i) {
    if (par[i] == 0) continue;
    int u = par[i], v = i;
    u = node[u-1] + 1, v = node[v-1]+1;
    tmp[v] = u;
  }
  for (int i = 1; i <= n; ++i)
    par[i] = tmp[i];
  memset(tmp, -1, sizeof tmp);
  for (int i = 1; i <= n; ++i) {
    int u = node[i-1]+1;
    tmp[u] = lv[i];
  }
  for (int i = 1; i <= n; ++i)
    lv[i] = tmp[i];
}

int lca(int u, int v) {
  while (u != v) {
    if (lv[u] > lv[v])
      u = par[u];
    else
      v = par[v];
  }
  return v;
}

void generate(int n, int max_m) {
  int m = rand_int(1, max_m);
  printf("%d %d\n", n, m);
  lv[1] = 0;
  for (int i = 2; i <= n; ++i) {
    par[i] = rand_int(1, i-1);
    lv[i] = lv[par[i]] + 1;
  }
  for (int i = 0; i < m; ++i) {
    int u = rand_int(1, n);
    int v = rand_int(1, n);
    while (v == u) {
      v = rand_int(1, n);
    }
    int w = lca(u, v);
    printf("%d %d %d\n", u, v, w);
  }
}

int main(int argc, char * argv[]) {
  int seed = 13513073;
  int n = 60, max_m = 120;
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  if (argc >= 3)
    n = atoi(argv[2]);
  if (argc >= 4)
    max_m = atoi(argv[3]);
  cerr << "seed\t= " << seed << endl;
  cerr << "n\t= " << n << endl;
  cerr << "max_m\t= " << max_m << endl;
  srand(seed);
  int t = 100;
  printf("%d\n", t);
  for (int i = 0; i < t; ++i)
    generate(n, max_m);
  return 0;
}
