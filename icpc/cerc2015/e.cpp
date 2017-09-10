#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 3e5, M = 3e5, Q = 3e5;
pii ans[Q + 5];
pii pri[Q + 5];

piii edge[M + 5];
int par[N + 5];
int deg2[N + 5];
int deg[N + 5];
int SZ[N + 5];

int n, m, q;
void initpar(){
  for(int i = 1;i <= n; ++i) {
    par[i] = i;
    SZ[i] = 1;
  }
}

int findset(int a){
  return a == par[a] ? a : par[a] = findset(par[a]);
}

bool disjoint(int a, int b){
  return findset(a) != findset(b);
}

int main(){
  scanf("%d%d", &n, &m);
  initpar();
  for(int i = 0;i < m; ++i){
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    edge[i] = mp(c, mp(x, y));
  }
  for(int i = 0;i < q; ++i){
    scanf("%d", &pri[i].fi);
    pri[i].se = i;
  }
  sort(edge, edge + m);
  sort(pri, pri + q);
  reverse(pri, pri +q);
  reverse(edge, edge + m);

  preprocess();
  for(int i = 0, poi = 0, node = 0, e = 0; i < q; ++i){
    while(poi < m && edge[poi].fi >= pri[i].fi){
      int u = edge[poi].se.fi;
      int v = edge[poi].se.se;
      int szawal_u = SZ[findset(u)];
      int szawal_v = SZ[findset(v)];
      int deg2awal_u = deg2[findset(u)];
      int deg2awal_v = deg2[findset(v)];

      deg[u]++;
      deg[v]++;
      ++e;
      if(deg[u] == 1){
        node++;
      }
      if(deg[v] == 1){
        node++;
      }
      if(deg[u] == 2){
        deg2[findset(u)]++;
      }
      if(deg[v] == 2){
        deg2[findset(v)]++;
      }
      if(deg[u] == 3){
        deg2[findset(u)]--;
      }
      if(deg[v] == 3){
        deg2[findset(v)]--;
      }

      if(disjoint(u, v)){
        int mins = min(findset(u), findset(v));
        int maks = max(findset(u), findset(v));
        SZ[mins] += SZ[maks];
        deg2[mins] += deg2[maks];
        ans[pri[i].se] = mp(node - deg2[mins] + (szawal_u == deg2awal_u) + (szawal_v == deg2awal_v), e - deg2[mins] + (szawal_u == deg2awal_u) + (szawal_v == deg2awal_v));
      }
      else{
       ans[pri[i].se] = mp(node - deg2[mins] + (szawal_u == deg2awal_u) + (szawal_v == deg2awal_v), e - deg2[mins] + (szawal_u == deg2awal_u) + (szawal_v == deg2awal_v)); 
      }

      ++poi;
    }
  }

  for(int i = 0;i < q; ++i){
    printf("%d %d\n", ans[i].fi, ans[i].se);
  }
  return 0;
}