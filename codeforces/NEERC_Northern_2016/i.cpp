#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;
int x[N], y[N];
int cnt[2][2][2];

int main() {
  freopen("integral.in", "r", stdin);
  freopen("integral.out", "w", stdout);
  int n;
  scanf("%d", &n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x+i, y+i);
    if (i) {
      cur += (1LL * x[i] * y[i-1] - 1LL * x[i-1] * y[i]) % 2;
      cur = (cur + 2) % 2;
    }
    int xx = x[i] % 2, yy = y[i] % 2;
    if (xx < 0)
      xx += 2;
    if (yy < 0)
      yy += 2;
    cnt[cur][xx][yy]++;
    // cerr << cur << " " << xx << " " << yy << " " << cnt[cur][xx][yy] << endl;
  }
  cur += (1LL * x[0] * y[n-1] - 1LL * x[n-1] * y[0]) % 2;
  cur = (cur + 2) % 2;
  if (cur) {
    puts("0");
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int a = 0; a < 2; a++) {
          for (int b = 0; b < 2; b++) {
            int crs = (j * b - k * a) % 2;
            if (crs < 0) crs += 2;
            if (crs) continue;
            ans += 1LL * cnt[i][j][k] * cnt[i][a][b];
          }
        }
      }
    }
  }
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 2; k++) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          int crs = (j * b - k * a) % 2;
          if (crs < 0) crs += 2;
          if (crs == 0) continue;
          ans += 1LL * cnt[0][j][k] * cnt[1][a][b] + 1LL * cnt[1][j][k] * cnt[0][a][b];
        }
      }
    }
  }
  ans -= n;
  ans /= 2;
  ans -= n;
  printf("%lld\n", ans);
  return 0;
}