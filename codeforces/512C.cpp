#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

int n, a[202], res[205][205], f, t, s;
bitset < 20015 > isprime;
bitset < 205 > vis;
vector< vi > ans;
vi p, q;

void augment(int v, int minEdge) {
  if(v == p[v])
    return;
  if(v == s) { f = minEdge; return; }
  if(p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]));
    if(f)
      q[p[v]] = v;
    res[v][p[v]] += f;
    res[p[v]][v] -= f;
  }
}

int main() {
#ifdef DEBUG
  time_t startt = clock();
#endif
  isprime.set();
  isprime[0] = isprime[1] = 0;
  for(int i = 0; i<20015; i++)
  if(isprime[i]) {
    for(int j = i*i; j<20015; j+= i)
      isprime[j] = 0;
  }
  scanf("%d", &n);
  p.assign(n+2, 0);
  q.assign(n+2, 0);
  int cnt[] = {0, 0};
  s = n; t = n+1;
  memset(res, 0, sizeof res);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
    if(a[i] & 1) {
      cnt[0]++;
      res[s][i] = 2;
    }
    else {
      res[i][t] = 2;
      cnt[1]++;
    }
  }
  if(cnt[0] != cnt[1]) {
    puts("Impossible");
    return 0;
  }
  for(int i = 1; i<n; i++)
    for(int j = 0; j<i; j++)
      if(isprime[a[i]+a[j]]) {
        if(a[i] & 1)
          res[i][j] = 1; 
        else
          res[j][i] = 1;
      }
  int flow = 0;
  n += 2;
  while(1) {
    f = 0;
    vis.reset();
    queue< int > q;
    p.assign(n, -1);
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int i = 0; i<n; i++)
        if(!vis[i] && res[u][i] > 0)
          p[i] = u, vis[i] = 1, q.push(i);
    }
    augment(t, 1000000);
    if(f == 0) break;
    flow += f;
  }
  if(flow != (cnt[0]<<1)) {
    puts("Impossible");
    return 0;
  }
  vis.set();
  n -= 2;
  for(int i = 0; i<n; i++) if(vis[i] && (a[i] & 1)) {
    int v = i;
    ans.push_back(vi());
    while(vis[v]) {
      ans.back().push_back(v);
      vis[v] = 0;
      for(int j = 0; j<n; j++) {
        if(vis[j] && ((a[j] & 1) == 0) && res[j][v]) {
          v = j;
          break;
        }
      }
      ans.back().push_back(v);
      vis[v] = 0;
      for(int j = 0; j<n; j++)
        if(vis[j] && (a[j] & 1) && res[v][j]) {
          v = j;
          break;
        }
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i<ans.size(); i++) {
    printf("%d", ans[i].size());
    for(int j = 0; j< ans[i].size(); j++)
      printf(" %d", ans[i][j] + 1);
    printf("\n");
  }
#ifdef DEBUG
  cerr << "Running time  : " << (double)(clock()-startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  int T = time(NULL)-1491365861;
  cerr << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
#endif
  return 0;
}
