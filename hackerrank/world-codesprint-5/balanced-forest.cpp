#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int awal[N], ans, c[N], cntr, fst[N], last[N];
long long b[N], sum[N];
vector< int > adj[N];
long long dfs(int v, int par = -1) {
  int aw = cntr;
  long long tmp = c[v];
  for(int u : adj[v]) if(u != par) {
    tmp += dfs(u, v);
  }
  awal[cntr] = aw;
  sum[cntr] = tmp;
  cntr++;
  return tmp;
}

int main() {
  int q;
  scanf("%d", &q);
  while(q--) {
    scanf("%d", &n);
    long long all = 0;
    for(int i = 0; i<n; i++) {
      scanf("%d", c+i);
      all += c[i];
      adj[i].clear();
    }
    for(int i = 1; i<n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cntr = 0;
    assert(dfs(0) == all);
    assert(cntr == n);
    for(int i = 0; i<n; i++)
      b[i] = sum[i];
    sort(b, b+n);
    int m = unique(b, b+n)-b;
    memset(fst, -1, sizeof fst);
    memset(last, -1, sizeof last);
    long long ans = all;
    for(int i = 0; i<n; i++) {
      int id = lower_bound(b, b+m, sum[i])-b, tid = id;
      if(fst[id] < 0)
        fst[id] = i;
      if(fst[id] < awal[i] && 3*sum[i] >= all) {
        ans = min(ans, 3LL*sum[i]-all);
        // cerr << "1" << endl;
      }
      long long res = all - sum[i]*2;
      id = lower_bound(b, b+m, res)-b;
      if(id < m && b[id] == res && all <= 3*sum[i]) {
        if(fst[id] >= 0 && fst[id] < awal[i]) {
          ans = min(ans, 3*sum[i] - all);
          // cerr << "cuk";
        }
      }
      res = all - sum[i];
      if((res & 1) == 0) {
        res /= 2;
        id = lower_bound(b, b+m, res)-b;
        if(fst[id] >= 0 && id < m && b[id] == res && fst[id] < awal[i] && 3*res >= all) {
          ans = min(ans, 3*res - all);
          // cerr << "dor";
        }
      }
      if((sum[i] & 1) == 0) {
        res = sum[i]/2;
        id = lower_bound(b, b+m, res)-b;
        if(id<m && b[id] == res && last[id] >= awal[i] && 3*res >= all)
          ans = min(ans, 3*res-all);
      }
      res = all-sum[i];
      if(res < sum[i]) {
        id = lower_bound(b, b+m, res)-b;
        if(id<m && b[id] == res && last[id] >= awal[i] && 3*res >= all)
          ans = min(ans, 3*res-all);
        long long rr = sum[i]-res;
        id = lower_bound(b, b+m, rr)-b;
        if(id<m && (b[id] == (sum[i] - res)) && last[id] >= awal[i] && 3*res >=all)
          ans = min(ans, 3*res-all);
      }
      last[tid] = i;
    }
    if(ans >= all)
      ans = -1;
    printf("%lld\n", ans);
  }
  return 0;
}