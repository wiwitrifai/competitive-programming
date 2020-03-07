#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], p[N];
vector<int> val[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (p[u] > p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return true;
}

int main() {
  memset(p, -1, sizeof p);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    val[x].push_back(i);
  }
  long long ans = 0;
  for (int d = N-1; d > 0; --d) {
    int last = -1;
    for (int j = d; j < N; j += d) {
      for (int x : val[j]) {
        if (last == -1)
          last = x;
        else {
          if (merge(last, x)) {
            ans += d;
          }
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
