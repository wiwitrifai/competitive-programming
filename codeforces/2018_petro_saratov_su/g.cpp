#include <bits/stdc++.h>

using namespace std;

const int N = 2018;
const double inf = 1e8;

vector<pair<int, int> > g[N];

double st[N];
bool ok[N];

string s;

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = 0; i < n; ++i) {
      cin >> s;
      if (s[0] == '?')
        ok[i] = 1;
      else
        st[i] = (double)stoi(s), ok[i] = 0;
      g[i].clear();
    }
    for (int i =0; i < m; ++i) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w); --u, --v;
      g[v].emplace_back(u, w);
    }
    double l = 0, r = inf;
    for (int it = 0; it < 300; ++it) {
      double mid = (l + r) * 0.5;
      for (int i = 0; i < n; ++i) {
        if (!ok[i]) continue;
        st[i] = inf;
      }
      bool can = 1;
      for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
          for (auto it : g[i]) {
            int u = it.first, w = it.second;
            double d = st[i] + mid - w;
            if (ok[u])
              st[u] = min(st[u], d);
          }
        }
      }
      for (int i = 0; i < n && can; ++i) {
        for (auto it : g[i]) {
          int u = it.first, w = it.second;
          if (st[u] + w > st[i] + mid) {
            can = 0;
            break;
          }
        }
      }
      if (can)
        r = mid;
      else
        l = mid;
    }
    for (int i = 0; i < n; ++i) {
      if (ok[i])
        st[i] = inf;
    }
    for (int k = 0; k < n; ++k) 
      for (int i = 0; i < n; ++i) {
        for (auto it : g[i]) {
          int u = it.first, w = it.second;
          double d = st[i] + l - w;
          if (ok[u])
            st[u] = min(st[u], d);
        }
      }
    printf("%.10lf\n", l);
    for (int i = 0; i < n; ++i)
      printf("%.10lf%c", st[i], (i==n-1) ? '\n' : ' ');
  }
  return 0;
}
