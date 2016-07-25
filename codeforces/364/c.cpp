#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, M = 3e4 + 5, inf = 2e9 + 5;
int n, m, a[M], b[M], c[M], state[M], num[N], low[N], cntr, num2[N], low2[N], cntr2;
vector< int > adj[N];
int ans, nans, id[2], ok[N];
vector< int > st;

int dfs2(int v, int last = -1) {
  num2[v] = low[v] = cntr2++;
  int ret = -1
  for(int i : adj[v]) {
    int u = a[i] + b[i] - v, w = c[i];
    if(!ok[u])
      continue;
    if(num2[u] == -1) {
      int res = dfs2(u, i);
      if(ret == -1 || (res != -1 && c[res] < c[ret]))
        ret = res;
      if(low[u] > num[v]) {
        if(ret == -1 || (i != -1 && c[i] < c[ret]))
          ret = i;
      }
      low2[v] = min(low2[v], low2[u]);
    }
    else if(i != last) {
      low2[v] = min(low2[v], num2[u]);
    }
  }
  return ret;
}
void dfs(int v, int last = -1) {
  st.push_back(v);
  num[v] = low[v] = cntr++;
  for(int i : adj[v]) {
    int u = a[i] + b[i] - v, w = c[i];
    if(num[u] == -1) {
      dfs(u, i);
      if(low[u] > num[v]) {
        state[i] = 0;
        if(ans < w) {
          ans = w;
          nans = 1;
          id[0] = i;
        }
      }
      low[v] = min(low[v], low[u]);
    }
    else if(i != last) {
      low[v] = min(low[v], num[u]);
    }
  }
  if(num[v] == low[v]) {
    int x = (int)st.size()-1;
    while(st[x] != v) {
      ok[st[x]] = 1;
      x--;
    }
    ok[v] = 1;
    for(int i = x; i<st.size(); i++) {
      int u = st[i];
      for(int j : adj[u]) if(ok[a[j]] && ok[b[j]] && state[j] == 1) {
        state[j] = 0;
        memset(num2, -1, sizeof num2);
        int res = dfs2(v);
        if(res != -1 && (c[res] + c[j]) < ans) {
          ans = c[res] + c[j];
          nans = 2;
          id[0] = res, id[1] = j;
        }
        state[j] = -1;
      }
    }
    while(st.back() != v) {
      ok[st.back()] = 0;
      st.pop_back();
    }
    st.pop_back();
  }
}

int main() {
  scanf("%d%d", &n, &m);
  int s, t;
  scanf("%d%d", &s, &t);
  for(int i = 0; i<m; i++) {
    scanf("%d%d%d", a+i, b+i, c+i);
    a[i]--; b[i]--;
    adj[a[i]].push_back(i);
    adj[b[i]].push_back(i);
  }
  ans = inf;
  nans = 0;
  cntr = 0;
  memset(num, -1, sizeof num);
  memset(state, 1, sizeof state);
  if(nans == 0)
    puts("-1");
  else {
    printf("%d\n", );
  }
  return 0;
}