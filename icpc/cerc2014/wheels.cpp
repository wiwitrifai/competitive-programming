#include <bits/stdc++.h>

using namespace std;

#define x first.first
#define y first.second
#define r second

pair< pair<int, int>, int > circ[1024];
pair< long long, long long > ans[1024];

bool ok[1024];
vector< int > adj[1024];

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

void dfs(int v, int p = -1) {
  ok[v] = true;
  if(p == -1) {
    ans[v] = make_pair(1, 1);
  }
  else {
    ans[v] = make_pair(-1LL*circ[p].r*ans[p].first, ans[p].second*circ[v].r);
    long long d = gcd(abs(ans[v].first), ans[v].second);
    ans[v].first /= d;
    ans[v].second /= d;
  }
  for(auto u : adj[v]) if(!ok[u]){
    dfs(u, v);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
      int xx, yy, rr;
      scanf("%d%d%d", &xx, &yy, &rr);
      circ[i] = make_pair(make_pair(xx, yy), rr);
    }
    for(int i= 0; i<n; i++)
      adj[i].clear();
    for(int i = 0; i<n; i++) {
      for(int j = i+1; j<n; j++) {
        int dx = circ[i].x - circ[j].x;
        int dy = circ[i].y - circ[j].y;
        int rr = circ[i].r + circ[j].r;
        if((dx*dx + dy*dy) == rr*rr) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    memset(ok, false, sizeof ok);
    dfs(0);
    for(int i = 0; i<n; i++) {
      if(!ok[i])
        puts("not moving");
      else {
        if(ans[i].second == 1)
          printf("%lld ", abs(ans[i].first));
        else
          printf("%lld/%lld ", abs(ans[i].first), ans[i].second);
        if(ans[i].first >= 0)
          puts("clockwise");
        else
          puts("counterclockwise");
      }
    }
  }
  return 0;
}