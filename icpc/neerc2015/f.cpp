#include <bits/stdc++.h>

using namespace std;

const string NAME = "froggy";
const double inf = 1e18;
const double eps = 1e-7;

const int N = 1005;

double dp[N][2];
pair<double, double> b[N][2];
int x[N], y[N];

double dist(int a, int b, int c, int d) {
  return sqrt(1LL * (a - c) * (a - c) + 1LL * (b - d) * (b - d));
}

pair<double, double> mid(int a, int b, int c, int d) {
  return {(double) (a + c) / 2, (double) (b + d) / 2};
}

int main() {
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
  
  int n, k;
  scanf("%d %d", &k, &n);
  for (int i = 1; i <= n; i++) scanf("%d %d", x + i, y + i);
  for (int i = 0; i <= n + 1; i++) dp[i][0] = dp[i][1] = inf;
  priority_queue<tuple<double, int, int>> pq;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = x[i];
    dp[i][1] = (double) x[i] / 2;
    b[i][1] = {(double) x[i] / 2, y[i]};
    
    for (int j = 0; j < 2; j++) {
      pq.emplace(-dp[i][j], i, j);
    }
  }
  while (!pq.empty()) {
    double c; int now, st;
    tie(c, now, st) = pq.top();
    c = -c;
    pq.pop();
    if (fabs(c - dp[now][st]) > eps) continue;
    //printf("%d %d: %.3f back %.3f %.3f\n", now, st, c, b[now][st].first, b[now][st].second);
    for (int i = 1; i <= n; i++) {
      double ncos = max(c, dist(x[now], y[now], x[i], y[i]));
      if (ncos + eps < dp[i][st]) {
        dp[i][st] = ncos;
        b[i][st] = b[now][st];
        pq.emplace(-dp[i][st], i, st);
      }
    }
    if (st == 0) {
      for (int i = 1; i <= n; i++) {
        double ncos = max(c, dist(x[now], y[now], x[i], y[i]) / 2);
        if (ncos + eps < dp[i][1]) {
          dp[i][1] = ncos;
          b[i][1] = mid(x[now], y[now], x[i], y[i]);
          pq.emplace(-dp[i][1], i, 1);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      double ncos = max(dp[i][j], (double) k - x[i]);
      if (ncos + eps < dp[n + 1][j]) {
        dp[n + 1][j] = ncos;
        b[n + 1][j] = b[i][j];
      }
      if (j == 0) {
        ncos = max(dp[i][j], (double) (k - x[i]) / 2);
        if (ncos + eps < dp[n + 1][1]) {
          dp[n + 1][1] = ncos;
          b[n + 1][1] = mid(x[i], y[i], k, y[i]);
        }
      }
    }
  }
  //printf("ans %.3f\n", dp[n + 1][1]);
  printf("%.3f %.3f\n", b[n + 1][1].first, b[n + 1][1].second);
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}