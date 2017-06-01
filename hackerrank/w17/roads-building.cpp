#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4, inf = 1e9;

typedef pair< int, int > ii;

int n, m, a[N], b[N];
vector< ii > adj[N];
long long ans, val, sum[N];

void dijkstra(int s, int d[]) {
  priority_queue< ii, vector< ii >, greater< ii > > pq;
  for(int i = 0; i<n; i++)
    d[i] = inf;
  d[s] = 0;
  pq.push(ii(d[s], s));
  while(!pq.empty()) {
    ii top = pq.top(); pq.pop();
    if(top.first != d[top.second])
      continue;
    int v = top.second;
    for(auto next : adj[v]) {
      int u = next.first;
      if(d[v] + next.second < d[u]) {
        d[u] = d[v] + next.second;
        pq.push(ii(d[u], u));
      }
    }
  }
}


int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--; v--;
    adj[u].push_back(ii(v, w));
    adj[v].push_back(ii(u, w));
  }
  dijkstra(0, a);
  dijkstra(n-1, b);
  val = b[0] - 1;
  ans = 0;
  for(int i = 0; i<n; i++) {
    if(a[i]+b[i] < val) {
      ans -= (val - a[i] - b[i]);
    }
  }
  sort(a, a+n);
  sort(b, b+n);
  sum[0] = 0;
  for(int i = 0; i<n; i++)
    sum[i+1] = a[i] + sum[i];
  int k = 0;
  for(int i = n-1; i>= 0; i--) {
    while(k < n && (a[k]+b[i]) < val) k++;
    ans += ((val-b[i])*k-sum[k]);
  }
  ans = max(ans, 0LL);
  printf("%lld\n", ans);
  return 0;
}