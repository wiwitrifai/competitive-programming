#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int dist[N][N];
vector< int > g[N];

void solve1(int n, int k) {
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i+1 < n; i++) {
    g[i].push_back(i+1);
    g[i+1].push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = N;
    }
    set< pair< int, int > > st;
    dist[i][i] = 0;
    st.insert(make_pair(dist[i][i], i));
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second;
      st.erase(it);
      for (int u : g[v]) {
        if (dist[i][u] > dist[i][v] + 1) {
          st.erase(make_pair(dist[i][u], u));
          dist[i][u] = dist[i][v] + 1;
          st.insert(make_pair(dist[i][u], u));
        }
      }
    }
    for (int j = i; j < n; j++)
      ans += dist[i][j];
  }
  cout << ans << "\n";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n < 100) {
      // cerr << "small " << endl;
      solve1(n, k);
    }
    else if (k == 0) {
      long long ans = (1LL * (n-1) * n * (2 * n - 1) / 3 + 1LL * (n-1) * n)/4;
      cout << ans << endl;
    }
    else if (k == 1) {
      int a, b;
      scanf("%d %d", &a, &b);
      if (a > b)
        swap(a, b);
      long long le = a, ri = n-b+1, bulet = n-le-ri+2;
      int be = n;
      n = le + ri;
      long long ans = (1LL * (n-1) * n * (2 * n - 1) / 3 + 1LL * (n-1) * n)/4;
      n = be;
      if (bulet & 1) {
        long long tmp = (bulet)/2;
        // bulet vs bulet
        ans += 1LL * tmp * (tmp+1) / 2 * bulet - 1;
        // bulet vs le
        ans += (1LL * tmp * (tmp+1) - 1) * (le-1) + 1LL * (le-1) * le /2 * (bulet-2);
        ans += (1LL * tmp * (tmp+1) - 1) * (ri-1) + 1LL * (ri-1) * ri /2 * (bulet-2);
      }
      else {
        int tmp = (bulet)/2 - 1;
        ans += 1LL * tmp * (tmp+1) / 2 * bulet - 1 + (bulet/2) * (bulet/2);
        ans += (1LL * tmp * (tmp+1) + bulet/2 - 1) * (le-1) + 1LL * (le-1) * le /2 * (bulet-2);
        ans += (1LL * tmp * (tmp+1) + bulet/2 - 1) * (ri-1) + 1LL * (ri-1) * ri /2 * (bulet-2);
      }
      cout << ans << endl;
    }
    else {
      assert(false);
    }
  }
  return 0;
}