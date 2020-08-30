#include <bits/stdc++.h>

using namespace std;

double p;

const int N = 8080;
int cntr = 0;

int vis[N][N];
long double mem[N][N];

long double solve(int n, int k) {
  if (n == 1)
    return 0;
  if (vis[n][k] == cntr)
    return mem[n][k];
  vis[n][k] = cntr;
  long double & ret = mem[n][k];
  ret = 1;
  long double tot = n * (n - 1) / 2;
  if (k > 0) {
    long double lef = k;
    lef = lef * (lef - 1) / 2.0;
    long double cur = (long double) lef / tot;
    lef = k;
    long double rig = n - lef;
    cur += p * (lef * rig) / tot;
    ret += solve(n-1, k-1) * cur;
  }
  if (k+1 < n) {
    long double rig = (n-k-1);
    rig = rig * (rig - 1) / 2;
    long double cur = (long double) rig / tot;
    rig = n - k - 1;
    long double lef = n - rig;
    cur += (1.0f - p) * (lef * rig) / tot;
    ret += solve(n-1, k) * cur;
  }
  return ret;
}

void solve() {
  ++cntr;
  int n;
  scanf("%d %lf", &n, &p);
  for (int i = 0; i < n; ++i) {
    printf("%.9lf\n", (double)solve(n, i));
  }
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
    printf("Case #%d:\n", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
