#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N = 2e4, M = 2e4;
int prim[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
LL mult[15];

LL ar[N + 5];
int gold[N + 5];
map<LL, int> MAP;
int n, m;
vector<pii> ve[N + 5];
priority_queue<pii, vector<pii>, greater<pii> > pq;
int dp[N + 5];
int dist[N + 5];
bool visit[N + 5];
const int INF = 1e9;

int start = 0, finish = 0;

inline int rek(int x){

  if(x == start) return gold[x];
  if(dp[x] != -1) return dp[x];
  int ret = dp[x] = -INF;
  for(int i = 0;i < ve[x].size(); ++i){
    pii u = ve[x][i];
    if(dist[u.fi] + u.se == dist[x]){
      ret = max(ret, rek(u.fi));
    }
  }
  ret += gold[x];
  return ret;
}
int main(){
  mult[0] = prim[0];
  for(int i = 1;i < 15; ++i) mult[i] = mult[i - 1] * prim[i];

  scanf("%d%d", &n, &m);
  for(int i = 0;i < n; ++i){
    scanf("%lld", &ar[i]);
    MAP[ar[i]] = i;
    gold[i] = upper_bound(mult, mult + 15, ar[i]) - mult;
  }
  
  for(int i = 0;i < n; ++i){
    if(ar[i] < ar[start]) start = i;
    else if(ar[i] > ar[finish]) finish = i;
  }

  for(int i = 0;i < m; ++i){
    LL x, y;
    int d;
    scanf("%lld%lld%d", &x, &y, &d);
    int xx = MAP[x];
    int yy = MAP[y];
    ve[xx].push_back(mp(yy, d));
    ve[yy].push_back(mp(xx, d));
  }
  memset(dist, -1, sizeof dist);
  dist[start] = 0;
  pq.push(mp(0, start));
  while(!pq.empty()){
    pii top = pq.top();
    pq.pop();
    if(visit[top.se]) continue;
    visit[top.se] = 1;
    for(int i = 0;i < ve[top.se].size(); ++i){
      pii now = ve[top.se][i];
      if(dist[now.fi] == -1 || dist[now.fi] > dist[top.se] + now.se){
        dist[now.fi] = dist[top.se] + now.se;
        pq.push(mp(dist[now.fi], now.fi));
      }
    }
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", rek(finish));

  return 0;
}