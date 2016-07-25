#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, k;
bool uni[N];
vector< int > adj[N];
int cnt[N], ch[N];

int pre(int v, int par = -1) {
  int ret = uni[v], ma = 0;
  for(int u : adj[v]) if(u != par) {
    int res = pre(u, v);
    ret += res;
    ma = max(ma, res);
  }
  cnt[v] = ret;
  ch[v] = ma;
  return ret;
} 

long long get(int v, int val = 0, int par = -1) {
  long long ret = val;
  int big = max(ch[v] * 2 - cnt[v] - val, 0);
  for(int u : adj[v]) if(u != par) {
    int sisa = cnt[u];
    if(cnt[u] == ch[v]) {
      sisa = cnt[u] - big;
    }
    ret += get(u, sisa, v);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  memset(uni, false, sizeof uni);
  for(int i = 0; i<k*2; i++) {
    int u;
    scanf("%d", &u);
    uni[u-1] = true;
  }
  for(int i = 1; i<n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  pre(0, 0);

  cout << get(0) << endl;

  return 0;
}