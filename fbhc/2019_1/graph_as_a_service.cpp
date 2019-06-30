#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf =  1e9 + 7;

int x[N], y[N], z[N];
int n, m;

void read_input() {
  scanf("%d %d", &n, &m);
  assert(n <= 50);
  assert(m <= 1000);
  set<pair<int, int> > edges;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", x+i, y+i, z+i);
    assert(x[i] != y[i]);
    assert(1 <= x[i] && x[i] <= n);
    assert(1 <= y[i] && y[i] <= n);
    assert(1 <= z[i] && z[i] <= 1000000);
    assert(!edges.count({x[i], y[i]}));
    edges.insert({x[i], y[i]});
    edges.insert({y[i], x[i]});
  }
}

int g[N][N];

void solve() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      g[i][j] = inf;
    g[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    g[x[i]][y[i]] = z[i];
    g[y[i]][x[i]] = z[i];
  }
  for (int v = 1; v <= n; ++v) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j)
        g[i][j] = min(g[i][j], g[i][v] + g[v][j]);
    }
  }
  bool ok = 1;
  for (int i = 0; i < m; ++i) {
    if (g[x[i]][y[i]] != z[i]) {
      ok = 0;
      break;
    }
  }
  if (!ok) {
    puts("Impossible");
    return;
  }
  printf("%d\n", m);
  for (int i = 0; i < m; ++i)
    printf("%d %d %d\n", x[i], y[i], z[i]);
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
