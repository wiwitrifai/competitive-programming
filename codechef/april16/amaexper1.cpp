#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector< pair<int, int> > adj[N];
vector< int > st[N];
int f[N], d[N], lv[N], id[N], add[N], ans[N], cnt[N];

void dfs(int v, int p = -1) {
  f[v] = d[v] = 0;
  int ha, hi;
  ha = hi = 0;
  for(auto it : adj[v]) if(it.first != p) {
    lv[it.first] = lv[v] + 1;
    dfs(it.first, v);
    int now = f[it.first] + it.second;
    if(f[v] < now) {
      cnt[v] = 0;
      f[v] = now;
    }
    else if(f[v] == now)
      cnt[v]++;
    if(ha < now)
      ha = now;
    else
      hi = max(hi, now);
  }
  d[v] = ha + hi;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 1; i<n; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--; v--;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }
    lv[0] = 0;
    dfs(0);
    for(int i= 0; i<n; i++) id[i] = i;
    sort(id,id+n,[](int x, int y) { return lv[x] > lv[y]; });
    for(int i = 0; i<n; i++) {
      int now = id[i];
      add[now] = 0;
      st[now].clear();
      st[now].push_back(0);
      ans[now] = 0;
      if(cnt[now]) {
        vector< int > ls, pt;
        for(auto it : adj[now]) if((lv[it.first] > lv[now]) && (f[now] == f[it.first] + it.second)) {
          ls.push_back(it.first);
          int dd = add[it.first] + it.second;
          for(int j = 0; j<st[it.first].size(); j++)
            st[it.first][j] += dd;
        }
        pt.assign(ls.size(), 0);
        int fin = 0;
        while(fin < ls.size()) {
          int pil = ls[0];
          for(int j = 1; j<ls.size(); j++) {
            int nx = ls[j];
            if(pt[nx] == st[nx].size())
              continue;
            if(pt[pil] == st[pil].size())
              pil = nx;
            else
              if(st[pil][pt[pil]] > st[nx][pt[nx]])
                pil = nx;
          }
          st[now].push_back(st[pil][pt[pil]]);
          pt[pil]++;
          if(pt[pil] == st[pil].size())
            fin++;
        }
      }
      else {
        for(auto it : adj[now]) if(lv[it.first] > lv[now] && f[now] == f[it.first] + it.second) {
          st[now] = st[it.first];
          add[now] = add[it.first] + it.second;
          break;
        }
      }
      auto it = lower_bound(st[now].begin(), st[now].end(), f[now] - d[now]/2);
      if(it != st[now].end())
        ans[now] = max(f[now] - *it, d[now] - f[now] + *it);
      if(it != st[now].begin()) {
        it--;
        if(ans[now])
          ans[now] = min(ans[now], max(f[now] - *it, d[now] - f[now] + *it));
        else
          ans[now] = max(f[now] - *it, d[now] - f[now] + *it);
      }
    }
    for(int i = 0; i<n; i++)
      printf("%d\n", ans[i]);
  }
  return 0;
}