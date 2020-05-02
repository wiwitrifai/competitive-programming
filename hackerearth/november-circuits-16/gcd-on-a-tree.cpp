#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int p[N];
long long ans[N];
vector< pair<int, int > > edge[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    int d = gcd(u, v);
    edge[d].push_back(make_pair(u, v));
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i+i; j <= n; j += i)
      edge[i].insert(edge[i].end(), edge[j].begin(), edge[j].end());
  }
  memset(p, -1, sizeof p);
  for (int i = 1; i <= n; i++) {
    ans[i] = 0;
    for (auto e : edge[i]) {
      int u = e.first, v = e.second;
      u = find(u);
      v = find(v);
      if (u == v)
        continue;
      if (p[u] < p[v])
        swap(u, v);
      ans[i] -= 1LL * (-p[u]) * (-p[u] - 1);
      ans[i] -= 1LL * (-p[v]) * (-p[v] - 1); 
      p[v] += p[u];
      p[u] = v;
      ans[i] += 1LL * (-p[v]) * (-p[v] - 1);
    }
    for (auto e : edge[i]) {
      p[e.first] = p[e.second] = -1;
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = i+i; j <= n; j += i)
      ans[i] -= ans[j];
  }
  for (int i = 1; i <= n; i++)
    printf("%lld ", ++ans[i]);
  printf("\n");
  return 0;
}