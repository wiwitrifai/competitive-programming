#include <bits/stdc++.h>

using namespace std;

const int N = 605;
const double inf = 1e100;
const double eps = 1e-7;

int n, m;
int x[N], y[N];
double r[N][N], h[N][N];
double to[N][N][4];
double d[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

double dist(double ra, double rb, double ha, double hb) {
  return (ra + rb) / 2 * exp(3.5 * abs((hb - ha)/10 + 0.05));
}

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  int p;
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i <= p; i++) scanf("%d %d", x + i, y + i);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%lf", &r[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%lf", &h[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        int ti = i + dx[k];
        int tj = j + dy[k];
        if (valid(ti, tj)) {
          to[i][j][k] = dist(r[i][j], r[ti][tj], h[i][j], h[ti][tj]);
        }
      }
    }  
  }
  double ans = 0;
  for (int it = 0; it < p; it++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        d[i][j] = inf;
      }
    }
    d[x[it]][y[it]] = 0;
    priority_queue<tuple<double, int, int>> pq;
    pq.emplace(0, x[it], y[it]);
    while (!pq.empty()) {
      double cost;
      int ni, nj;
      tie(cost, ni, nj) = pq.top();
      pq.pop();
      cost = -cost;
      if (abs(cost - d[ni][nj]) > eps) continue;
      if (ni == x[it+1] && nj == y[it+1]) break;
      for (int k = 0; k < 4; k++) {
        int ti = ni + dx[k];
        int tj = nj + dy[k];
        if (valid(ti, tj)) {
          double ncos = cost + to[ni][nj][k];
          if (ncos < d[ti][tj]) {
            d[ti][tj] = ncos;
            pq.emplace(-ncos, ti, tj);
          }
        }
      }
    }
    ans += d[x[it+1]][y[it+1]];
  }
  printf("%d\n", (int) (ceil(ans) + 0.5));
  return 0;
}
