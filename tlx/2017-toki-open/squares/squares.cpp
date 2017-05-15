#include "squares.h"

#include <bits/stdc++.h>

using namespace std;
typedef pair< int, int   > point;
#define x first
#define y second
const int N = 2e4 + 5;
const int inf = 1e8 + 7;

point p[N];
int r[N];
vector< int > g[N];
int f[N];

int dist(int u, int v) {
  return max(abs(p[u].x-p[v].x), abs(p[u].y-p[v].y));
}

long long getTotalArea(int N, std::vector<int> X, std::vector<int> Y) {
  for (int i = 0; i < N; i++) {
    X[i] *= 2;
    Y[i] *= 2;
    p[i] = {X[i], Y[i]};
    r[i] = inf;
  }
  sort(p, p+N);
  for (int i = 0; i < N; i++) {
    r[i] = inf;
    for (int j = i-1; j >= 0; j--) {
      if (abs(p[i].x-p[j].x) >= 4 * r[i]) break;
      r[i] = min(r[i], dist(i, j)/2);
    }
    for (int j = i+1; j < N; j++) {
      if (abs(p[i].x-p[j].x) >= 4 * r[i]) break;
      r[i] = min(r[i], dist(i, j)/2);
    }
    for (int j = i-1; j >= 0; j--) {
      if (abs(p[i].x-p[j].x) >= 4 * r[i]) break;
      if (dist(i, j) <= 4 * r[i])
        g[j].push_back(i);
    }
    for (int j = i+1; j < N; j++) {
      if (abs(p[i].x-p[j].x) >= 4 * r[i]) break;
      if (dist(i, j) <= 4 * r[i])
        g[j].push_back(i);
    }
  }
  priority_queue< pair< int, pair<int, int> > > pq;
  for (int i = 0; i < N; i++) {
    for (int j : g[i])
      pq.push(make_pair(-dist(i, j)/2, make_pair(j, i)));
  }
  while (!pq.empty()) {
    auto it = pq.top(); pq.pop();
    int v = it.second.first, u = it.second.second, w = -it.first;
    if (f[v]) continue;
    int d = dist(u, v);
    if (f[u] && (w + f[u]) != d) continue;
    f[v] = w;
    for (int z : g[v]) if (!f[z]) {
       pq.push(make_pair(-dist(v, z)+f[v], make_pair(z, v)));
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++)
    ans += 1LL * f[i] * f[i];
  return ans;
}
