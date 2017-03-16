#include <bits/stdc++.h>

using namespace std;

const int N = 22;

double dp[N][N][N * N];
char buf[10000];

int main() {
  time_t start_t = clock();
  for (int i = 4; i < N; i++) {
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N * N; k++)
        dp[i][j][k] = 0;
    dp[i][0][0] = 1;
    for (int j = 0; j + 1 < N; j++) {
      double sum = 0;
      for (int k = 0; k < N * N; k++) {
        dp[i][j+1][k] = sum/i;
        sum += dp[i][j][k];
        if (k-i >= 0)
          sum -= dp[i][j][k-i];
      }
    }
  }
  cerr << "Preprocess done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int h, s;
    scanf("%d %d", &h, &s);
    double ans = 0;
    while (s--) {
      scanf("%s", buf);
      int x, y, z;
      x = y = z = 0;
      int id = 0;
      while (buf[id] != 'd') {
        x *= 10;
        x += buf[id]-'0';
        id++;
      }
      id++;
      while (buf[id] >= '0' && buf[id] <= '9') {
        y *= 10;
        y += buf[id] - '0';
        id++;
      } 
      if (buf[id]) {
        int sign = buf[id] == '+' ? +1 : -1;
        id++;
        while (buf[id]) {
          z *= 10;
          z += buf[id] - '0';
          id++;
        }
        z *= sign;
      }
      cerr << x << " " << y << " " << z << endl;
      double tmp = 0;
      for (int i = max(0, h-z); i <= x * y; i++) {
        tmp += dp[y][x][i];
      }
      if (ans < tmp)
        ans = tmp;
    }
    printf("Case #%d: %.9lf\n", tc, ans);
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}