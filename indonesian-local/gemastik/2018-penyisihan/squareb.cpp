#include <bits/stdc++.h>

using namespace std;

const int N = 500;

int t, d;

int a[N][N], b[N][N];
int xa[N], ya[N], xb[N], yb[N];

int main() {
  int n, m, l;
  scanf("%d %d %d %d", &n, &m, &t, &d);
  scanf("%d", &l);
  for (int i = 0; i < l; ++i) {
    scanf("%d %d %d %d", xa+i, ya+i, xb+i, yb+i);
    for (int x = xa[i]; x <= xb[i]; ++x) {
      for (int y = ya[i]; y <= yb[i]; ++y) {
        b[x][y] = 1;
      }
    }
  }

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      cerr << b[x][y];
    }
    cerr << endl;
  }
  cerr << endl;

  long long ans = 0;
  int s = t+d;
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < s; ++j) {
      for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
          int px = ((x+s-i) % s);
          int py = ((y+s-j) % s);
          a[x][y] = (px < t &&  py < t && ((px+py) & 1) == 0);
        }
      }
      int cnt = 0;
      for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
          cnt += a[x][y];
        }
      }
      cerr << i << " " << j << " " << cnt << endl;
      for (int k = 0; k < l; ++k) {
        int cur = 0;
        for (int x = xa[k]; x <= xb[k]; ++x) {
          for (int y = ya[k]; y <= yb[k]; ++y) {
            cur += a[x][y];
          }
        }
        cerr << k << " " << cur << endl;
        cnt -= cur;
      }
      if (i == 0 && j == 0)
      for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
          cerr << a[x][y];
        }
        cerr << endl;
      }
      cerr << cnt << endl;
      return 0;
    }
  }
  return 0;
}