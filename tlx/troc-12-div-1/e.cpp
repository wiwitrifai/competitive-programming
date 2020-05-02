#include <bits/stdc++.h>

using namespace std;

const int N = 251;

int a[N][N];
int sumx[N][N][N], sumy[N][N][N];

int main() {
  int n, l, r;
  scanf("%d %d %d", &n, &l, &r);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i]+j);
      for (int k = 0; k < N; ++k) {
        sumx[i][j][k] = (min(i, j) <= 0 ? 0 : sumx[i-1][j-1][k]) + (k >= a[i][j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = n-1; j >= 0; --j) {
      for (int k = 0; k < N; ++k) {
        sumy[i][j][k] = (i <= 0 ? 0 : sumy[i-1][j+1][k]) + (k >= a[i][j]);
      }
    }
  }
  auto get_x = [&](int i, int j, int ll, int rr) {
    if (i >= n) {
      int d = i - (n-1);
      i -= d;
      j -= d;
    }
    if (j >= n) {
      int d = j - (n-1);
      i -= d;
      j -= d;
    }
    return (i < 0 || j < 0) ? 0 : sumx[i][j][rr] - sumx[i][j][ll];
  };

  auto get_y = [&](int i, int j, int ll, int rr) {
    if (i >= n) {
      int d = i - (n-1);
      i -= d;
      j += d;
    }
    if (j < 0) {
      int d = 0 - j;
      i -= d;
      j += d;
    }
    return (i < 0 || j >= n) ? 0 : sumy[i][j][rr] - sumy[i][j][ll];
  };
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int d = 1; d < 2 * n; ++d) {
        int rr = min((r * d) / a[i][j], N-1), ll = max((l * d + a[i][j] - 1) / a[i][j] - 1, 0);
        if (ll >= rr) continue;
        int cnt = get_x(i+d, j, ll, rr) - get_x(i-1, j-d-1, ll, rr);
        cnt += get_x(i, j+d, ll, rr) - get_x(i-d-1, j-1, ll, rr);
        cnt += get_y(i+d-1, j+1, ll, rr) - get_y(i, j+d, ll, rr);
        cnt += get_y(i-1, j-d+1, ll, rr) - get_y(i-d, j, ll, rr);
        ans += 1LL * cnt * cnt;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
