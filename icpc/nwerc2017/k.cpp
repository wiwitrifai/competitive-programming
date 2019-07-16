#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

double dp[N][N * 2];
bool vis[N][N * 2];
int le[N * 2], ri[N * 2], tol[N * 2], tor[N * 2], rat[N];
double calc(int id, int x) {
  double & ret = dp[id][x];
  if (vis[id][x])
    return ret;
  vis[id][x] = 1;
  if (le[x] == ri[x]) {
    // cerr << id << " " << le[x] << " " << ri[x] << " " << 1 << endl;
    return ret = 1;
  }
  ret = 0;
  int l = tol[x], r = tor[x];
  assert(l && r);
  if (id <= ri[l]) {
    for (int i = le[r]; i <= ri[r]; ++i) {
      double p = (double)rat[id] / (rat[id] + rat[i]);
      ret += p * calc(i, r);
      // cerr << id << " " << x << " " <<  i << " " << p << " " << ret << endl;
    }
    ret *= calc(id, l);
  }
  else {
    for (int i = le[l]; i <= ri[l]; ++i) {
      double p = (double)rat[id] / (rat[id] + rat[i]);
      ret += p * calc(i, l);
      // cerr << id << " " << x << " " <<  i << " " << p << " " << ret << endl;
    }
    ret *= calc(id, r);
  }
  // cerr << id << " " << le[x] << " " << ri[x] << " " << ret << endl;
  return ret;
}

int cntr = 0;

int dfs(int l, int r) {
  // cerr << l << " " << r << endl;
  int x = ++cntr;
  le[x] = l;
  ri[x] = r;
  if (l == r)
    return x;
  int pw = 1;
  while (pw * 2 <= r-l+1) pw <<= 1;
  int mid;
  if (r-l+1 - pw < pw/2)
    mid = l+pw/2;
  else
    mid = r - pw + 1;
  tol[x] = dfs(l, mid-1);
  tor[x] = dfs(mid, r);
  return x;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", rat+i);
  sort(rat+1, rat+n);
  int root = dfs(0, n-1);
  // cerr << cntr << endl;
  printf("%.10lf\n", calc(0, root));
  return 0;
}