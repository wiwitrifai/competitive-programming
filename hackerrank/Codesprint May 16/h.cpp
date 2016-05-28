#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, c[N], sz[N], cnt[N], val[N];
vector< int > adj[N];
long long sum[N];

void dfs(int v, int par = -1) {
  sz[v] = 1;
  int tmp = cnt[c[v]];
  cnt[c[v]] = 1;
  int last = 1;
  for(int u : adj[v]) if(u != par) {
    dfs(u, v);
    sz[v] += sz[u];
    val[u] = cnt[c[v]] - last;
    last = cnt[c[v]];
  }
  cnt[c[v]] = tmp + sz[v];
}

void dfs2(int v, long long cur, int par = -1) {
  sum[v] = cur;
  for(int u: adj[v]) if(u != par) {
    int tmp = cnt[c[v]], tmp2 = cnt[c[u]];
    cnt[c[u]] = n;
    cnt[c[v]] = val[u] + n - sz[u];
    dfs2(u, cur + cnt[c[v]] + cnt[c[u]]- tmp - tmp2, v);
    cnt[c[v]] = tmp;
    cnt[c[u]] = tmp2;
  }
}

int main() {
  scanf("%d", &n);
  vector< int > tmp;
  for(int i = 0; i<n; i++) {
    scanf("%d", c+i);
    tmp.push_back(c[i]);
  }
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  for(int i = 0; i<n; i++)
    c[i] = lower_bound(tmp.begin(), tmp.end(), c[i]) - tmp.begin();
  for(int i = 1; i<n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // cerr << "ok" << endl;
  dfs(0);
  long long cur = 0;
  for(int i = 0; i<tmp.size(); i++)
    cur += cnt[i];
  // cerr << "prepare" << endl;
  dfs2(0, cur);
  for(int i = 0; i<n; i++)
    printf("%lld\n", sum[i]); 
  return 0;
}