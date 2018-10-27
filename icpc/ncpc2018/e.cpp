#include <bits/stdc++.h>

using namespace std;

map<int, double> mp;

int state[12];
int sum, depth;
int finish;

int get_hash() {
  int now = 0;
  for (int i = 0; i < 12; ++i)
    now = now * 6 + state[i];
  return now;
}

double solve() {
  if (sum <= 0)
    return 1;
  if (depth >= finish) {
    for (int i = 6; i < 12; ++i)
      if (state[i] > 0)
        return 0;
    return 1;
  }
  int now = get_hash();
  auto it = mp.find(now);
  if (it!= mp.end())
    return it->second;
  double ans = 0;
  for (int i = 0; i < 12; ++i) {
    if (state[i] == 0) continue;
    --state[i];
    if (i != 0 && i != 6)
      ++state[i-1];
    else
      --sum;
    ++depth;
    double res = solve();
    --depth;
    ++state[i];
    if (i != 0 && i != 6)
      --state[i-1];
    else
      ++sum;
    ans += res * state[i] / sum;
  }
  return mp[now] = ans;
}

int main() {
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++state[x-1];
  }
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    ++state[5+x];
  }
  sum = n+m;
  finish = d;
  depth = 0;
  printf("%.10lf\n", solve());
  return 0;
}