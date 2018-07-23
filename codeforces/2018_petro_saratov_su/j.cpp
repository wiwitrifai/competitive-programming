#include <bits/stdc++.h>

using namespace std;

const int M = 20, mod = 1e9 + 7, N = 2e5 + 5;

int a[N];
int ans[N];
int l[N], r[N];
int le[N][M], ri[N][M];
int n, m;
void solve(vector<int> & que, int lo, int hi) {
  if (que.empty()) return;
  if (hi - lo < 2) {
    for (int i : que)
      ans[i] = 1 + (a[lo] == 0);
    return;
  }
  int mid = (lo + hi) >> 1;
  for (int j = 0; j < m; ++j)
    le[mid][j] = ri[mid-1][j] = (j == 0);
  for (int i = mid-1; i >= lo; --i) {
    for (int j = 0; j < m; ++j) {
      le[i][j] = (le[i+1][j] + le[i+1][(m - a[i] + j) % m]) % mod;
    }
  }
  for (int i = mid; i < hi; ++i) {
    for (int j = 0; j < m; ++j) {
      ri[i][j] = (ri[i-1][j] + ri[i-1][(m - a[i] + j) % m]) % mod;
    }
  }
  vector<int> ql, qr;
  for (int i : que) {
    if (r[i] <= mid) ql.push_back(i);
    else if (l[i] >= mid) qr.push_back(i);
    else {
      ans[i] = 0;
      for (int j = 0; j < m; ++j) {
        ans[i] = (ans[i] + 1LL * le[l[i]][j] * ri[r[i]-1][(m-j) % m]) % mod;
      }
      if (ans[i] < 0) ans[i] += mod;
    }
  }
  solve(ql, lo, mid);
  solve(qr, mid, hi);
}

int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    vector<int > que;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", & x); x %= m;
      a[i] = x;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d %d", l+i, r+i);
      --l[i];
      que.emplace_back(i);
    }
    solve(que, 0, n);
    for (int i = 0; i < q; ++i)
      printf("%d\n", ans[i]);
  }
  return 0;
}