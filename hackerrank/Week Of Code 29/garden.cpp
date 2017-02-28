#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
int x[20], y[20], ca, cb;
vector< pair< int, int > > solution[30][30];
bool dfs(int n, int a, int b, int suma, int sumb) {
  if (n >= 12) {
    if (suma || sumb)
      return false;
    double tot = 0;
    for (int i = 0; i < 12; i++) {
      int dx = ca-x[i], dy = cb - y[i];
      tot += sqrt(dx * dx + dy * dy); 
    }
    tot = fabs(tot - round(tot));
    if (tot > 1e-12)
      return false;
    vector< pair<int, int> > tmp(12);
    for (int i = 0; i < 12; i++)
      tmp[i] = {x[i], y[i]};
    for (int i = 0; i < 12; i++)
      solution[x[i] + 12][y[i] + 12] = tmp;
    cerr << "found #" << ++cnt << endl;
    return true;
  }
  if (b > 12) a++, b = -12;
  if (a > 12) return false;
  int now = min(12-b+1, 12-n);
  if (12 * (12-n) + suma < 0 || a * now + (a+1) * (12-n-now) > 0)
    return false;
  x[n] = a, y[n] = b;
  int dx = a-ca, dy = b-cb;
  double dist = sqrt(dx * dx + dy * dy);
  dist = fabs(dist - round(dist));
  if (dist <= 1e-12 && a != x[0] && b != y[0] && dfs(n+1, a, b+1, suma + x[n], sumb + y[n])) return true;
  return dfs(n, a, b+1, suma, sumb);
}
long long dp[20][30][20];
long long count(int n, int x, int r) {
  if (n >= 12) {
    return r == 0;
  }
  if (x > 12)
    return 0;
  long long & ret = dp[n][x+12][r];
  if (ret != -1)
    return ret;
  ret = 0;
  for (int i = 0; i <= 12-n; i++) {
    ret += count(n+i, x+1, r);
    r = (r + x) % 12;
    if (r < 0)
      r += 12;
  }
  // cerr << n << " " << x << " " << r << endl;
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  cout << count(0, -12, 0) << endl;
  for (ca = -12; ca <= 12; ca++) {
    for (cb = -12; cb <= 12; cb++) {
      int cok = 0;
      for (int i = -12; i <= 12; i++) {
        for (int j = -12; j <= 12; j++) {
          int dx = i - ca, dy = j - cb;
          int dist2 = dx * dx + dy * dy;
          int dist = (int)(sqrt(dist2) + 0.5);
          if (dist * dist != dist2)
            cok++;
        }
      }
      cerr << ca << " " << cb << " " << cok << endl;
    }
  }
  // for (int i = -12; i <= 12; i++) {
  //   for (int j = -12; j <= 12; j++) {
  //     printf("{");
  //     for (int z = 0; z < 12; z++) {
  //       if (z)
  //         printf(",");
  //       printf("{%d,%d}", solution[i+12][j+12][z].first, solution[i+12][j+12][z].second); 
  //     }
  //     printf("}\n");
  //   }
  // }
  return 0;
}