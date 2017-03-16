#include "railroad.h"
#include <bits/stdc++.h>

using namespace std;

const int NS = 16;
const long long inf = 1e18;
long long dp[1<<NS][NS];

long long solve_small(vector< int > s, vector< int > t) {
  int n = (int) s.size();
  int nn = 1<<n;
  for (int i = 0; i < nn; i++) {
    for (int j = 0; j < n; j++)
      dp[i][j] = inf;
  }
  for (int i = 0; i < n; i++) {
    dp[1<<i][i] = 0;
  }
  for (int i = 0; i < nn; i++) {
    for (int j = 0; j < n; j++) if ((i & (1<<j)) && dp[i][j] < inf) {
      for (int k = 0; k < n; k++) if ((i & (1<<k)) == 0) {
        int mask = i | 1<<k;
        dp[mask][k] = min(dp[mask][k], dp[i][j] + max(t[j]-s[k], 0));
      }
    }
  }
  long long ans = inf;
  for (int i = 0; i < n; i++) {
    ans = min(ans, dp[nn-1][i]);
  }
  return ans;
}

const int N = 1e6 + 5;
int p[N], vs[N], vt[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

long long solve_zero_one(vector< int > s, vector< int > t) {
  memset(p, -1, sizeof p);
  vector< pair< int, int > > tt;
  set < pair< int, int > > st;
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    tt.push_back({t[i], i});
    st.insert({s[i], i});
    vs[i] = s[i];
    vt[i] = t[i];
  }
  sort(tt.begin(), tt.end());
  int cnt = n;
  for (int i = n-1; i >= 0; i--) {
    auto it = st.lower_bound({tt[i].first, tt[i].second});
    if (it == st.end())
      continue;
    if (find(it->second) == find(tt[i].second)) {
      it++;
      if (it == st.end())
        continue;
    }
    if (merge(tt[i].second, it->second)) {
      cnt--;
    }
  }
  return cnt-1;
}

long long plan_roller_coaster(std::vector<int> s, std::vector<int> t) {
    int n = (int) s.size();
    if (n < 20)
      return solve_small(s, t);
    return solve_zero_one(s, t);
}

// int main() {
//   int n;
//   scanf("%d", &n);
//   vector< int > s, t;
//   for (int i = 0; i < n; i++) {
//     int x;
//     scanf("%d", &x);
//     s.push_back(x);
//   }
//   for (int i = 0; i < n; i++) {
//     int x;
//     scanf("%d", &x);
//     t.push_back(x);
//   }
//   printf("%lld\n",plan_roller_coaster(s, t));
//   return 0;
// }