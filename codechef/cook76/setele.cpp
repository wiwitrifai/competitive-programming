#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
long long merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return 0;
  if (p[u] < p[v])
    swap(u, v);
  long long ret = 1LL * p[u] * p[v];
  p[v] += p[u];
  p[u] = v;
  return ret;
}

int main() {
  memset(p, -1, sizeof p);
  int n;
  scanf("%d", &n);
  vector < pair< int, pair<int, int > > > edge;
  long double sum = 0;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    u--; v--;
    edge.push_back({c, {u, v}});
    sum += c;
  } 
  sum *= 1LL * n * (n-1) / 2;
  sort(edge.begin(), edge.end());
  for (int i = 0; i < edge.size(); i++) {
    sum -= 1LL * merge(edge[i].second.first, edge[i].second.second) * edge[i].first;
  }
  printf("%.13lf\n", (double)sum*2.0/n/(n-1));
  return 0;
}