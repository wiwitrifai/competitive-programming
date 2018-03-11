// by radit
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
vector<int> ans[3];

inline void GENERATE(int cnt, int a, int b, int c){
  if(a == 0) return; 
  vector<pii> v = {mp(a, 0), mp(b, 1), mp(c, 2)};
  sort(v.begin(), v.end());
  for(int i = 0;i < v[2].fi; ++i){
    ans[2 - v[2].se].pb(cnt);
  }
  int poia = 0, poib = 0;
  if(v[0].se == 0 && v[1].se == 1) poia = 1, poib = 2;
  else if(v[0].se == 0 && v[1].se == 2) poia = 0, poib = 2;
  else if(v[0].se == 1 && v[1].se == 0) poia = 2, poib = 1;
  else if(v[0].se == 1 && v[1].se == 2) poia = 0, poib = 1;
  else if(v[0].se == 2 && v[1].se == 0) poia = 2, poib = 0;
  else if(v[0].se == 2 && v[1].se == 1) poia = 1, poib = 0;
  ans[poia].pb(cnt); ans[poib].pb(cnt);
  for(int i = 1;i < v[0].fi; ++i) {
    ans[poia].pb(cnt + i);
    ans[poib].pb(cnt);
  }
  for(int i = 1;i < v[1].fi; ++i){
    ans[poia].pb(cnt);
    ans[poib].pb(cnt + i);
  }
  int sisa = v[2].fi - v[1].fi - v[0].fi + 1;
  for(int i = 1;i < v[0].fi && sisa; ++i){
    for(int j = 1;j < v[1].fi && sisa; ++j){
      ans[poia].pb(cnt + i); ans[poib].pb(cnt + j); sisa--;
    }
  }
}

int main() {
  
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  vector<int> v = {a, b, c};
  sort(v.begin(), v.end());
  if(v[0] * v[1] < v[2]){
    puts("-1");
    return 0;
  }

  int nowa = a, nowb = b, nowc = c;
  int cnt = 0;
  while(v[0] + v[1] - 1 > v[2]){
    ans[0].push_back(cnt);
    ans[1].push_back(cnt);
    ans[2].push_back(cnt);
    v[0]--;v[1]--;v[2]--;
    nowa--;
    nowb--;
    nowc--;
    cnt++;
  }

  //bagi 6 case
  GENERATE(cnt, nowa, nowb, nowc);
  assert(ans[0].size() == ans[1].size() && ans[1].size() == ans[2].size());

  printf("%d\n", (int) ans[0].size());
  for(int i = 0;i < (int) ans[0].size(); ++i){
    printf("%d %d %d\n", ans[0][i], ans[1][i], ans[2][i]);
  }
  return 0;
}