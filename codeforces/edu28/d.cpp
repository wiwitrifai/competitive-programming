#include <bits/stdc++.h>

using namespace std;

const int N = 505, M = N * N * 2;

int a[N][N];
int x[M], y[M], t[M];
int n, m, k, q;

bool cek(int c) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < q; i++)
    if (t[i] <= c)
      a[x[i]][y[i]] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) continue;
      a[i][j] = 1 + min(i > 0 ? a[i-1][j] : 0, min(j > 0 ? a[i][j-1] : 0, (i > 0 && j > 0) ? a[i-1][j-1] : 0));
      if (a[i][j] >= k)
        return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %d %d %d", &n, &m, &k, &q);
  vector<int> vt;
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", x+i, y+i, t+i);
    x[i]--; y[i]--;
    vt.push_back(t[i]);
  } 
  sort(vt.begin(), vt.end());
  vt.erase(unique(vt.begin(), vt.end()), vt.end());
  int l = 0, r = vt.size();
  while (l < r) {
    int mid = (l + r) / 2;
    if (cek(vt[mid]))
      r = mid;
    else
      l = mid + 1;
  }
  vt.push_back(-1);
  printf("%d\n", vt[l]);
  return 0;
}