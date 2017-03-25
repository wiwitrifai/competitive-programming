#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
pair< int, int> e[N];
map< int, int > mp[N];
int deg[N], n, m, loop[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[i] = {u, v};
    if (u == v) {
      loop[u]++;
      continue;
    }
    deg[u]++;
    deg[v]++;
    mp[u][v]++;
    mp[v][u]++;
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int u = e[i].first, v = e[i].second;
    if (u == v) {
      int mid = loop[u]-1;
      ans = (ans + 1LL * mid * (mid - 1));
      int other = deg[u];
      ans = (ans + 1LL * other * mid * 2);
      ans = (ans + 1LL * other * (other - 1));
    }
    else {
      int mid = mp[u][v];
      int otheru = deg[u] - mid + loop[u], otherv = deg[v] - mid + loop[v];
      mid--;
      ans = (ans + 1LL * mid * (mid - 1));
      ans = (ans + 1LL * otheru * mid * 2);
      ans = (ans + 1LL * mid * otherv * 2);
      ans = (ans + 1LL * otheru * otherv * 2);
    }
  }
  cout << ans << endl;
  return 0;
}