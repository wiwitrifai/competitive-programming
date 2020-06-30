// Coded by raditya1710

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1000;
const int K = 1000;
const LL INF = 1000000000000000LL;

LL dp[N + 5][K][8];
bool visit[N + 5][K][8];
int ar[N + 5][3];

int n, k;

LL rek(int pos, int sisak, int bitmask){
  if(sisak == 0) return 0;
  if(sisak < 0) return -INF;
  if(pos == n) return -INF; // assume it's handled in the sisak above

  if(visit[pos][sisak][bitmask]) return dp[pos][sisak][bitmask];

  visit[pos][sisak][bitmask] = 1;
  LL &ret = dp[pos][sisak][bitmask] = -INF;


  if(bitmask == 0){
    ret = max(ret, rek(pos, sisak - 1, 3) + ar[pos][0] + ar[pos][1]);
    ret = max(ret, rek(pos, sisak - 1, 6) + ar[pos][1] + ar[pos][2]);
    if(pos + 1 < n){
      ret = max(ret, rek(pos + 1, sisak - 1, 1) + ar[pos][0] + ar[pos + 1][0]);
      ret = max(ret, rek(pos + 1, sisak - 1, 2) + ar[pos][1] + ar[pos + 1][1]);
      ret = max(ret, rek(pos + 1, sisak - 1, 4) + ar[pos][2] + ar[pos + 1][2]);
      ret = max(ret, rek(pos + 1, sisak - 2, 5) + ar[pos][0] + ar[pos + 1][0] + ar[pos][2] + ar[pos + 1][2]);
    }
  }
  else if (bitmask == 1){ // paling kiri
    ret = max(ret, rek(pos, sisak - 1, 7) + ar[pos][1] + ar[pos][2]);
    if(pos + 1 < n){
      ret = max(ret, rek(pos + 1, sisak - 1, 2) + ar[pos][1] + ar[pos + 1][1]);
      ret = max(ret, rek(pos + 1, sisak - 1, 4) + ar[pos][2] + ar[pos + 1][2]);
    }
  }
  else if (bitmask == 2){ // paling tengah
    if(pos + 1 < n){
      ret = max(ret, rek(pos + 1, sisak - 1, 1) + ar[pos][0] + ar[pos + 1][0]);
      ret = max(ret, rek(pos + 1, sisak - 1, 4) + ar[pos][2] + ar[pos + 1][2]);
      ret = max(ret, rek(pos + 1, sisak - 2, 5) + ar[pos][0] + ar[pos + 1][0] + ar[pos][2] + ar[pos + 1][2]);
    }
  }
  else if (bitmask == 3){
    if(pos + 1 < n){
      ret = max(ret, rek(pos + 1, sisak - 1, 4) + ar[pos][2] + ar[pos + 1][2]);
    }
  }
  else if (bitmask == 4){ // paling kanan
    ret = max(ret, rek(pos, sisak - 1, 7) + ar[pos][0] + ar[pos][1]);
    if(pos + 1 < n){
      ret = max(ret, rek(pos + 1, sisak - 1, 1) + ar[pos][0] + ar[pos + 1][0]);
      ret = max(ret, rek(pos + 1, sisak - 1, 2) + ar[pos][1] + ar[pos + 1][1]);
    }
  }
  else if (bitmask == 5){
    if(pos + 1 < n){
      ret = max(ret, rek(pos + 1, sisak - 1, 2) + ar[pos][1] + ar[pos + 1][1]);
    }
  }
  else if (bitmask == 6){
    if(pos + 1 < n){
      ret = max(ret, rek(pos + 1, sisak - 1, 1) + ar[pos][0] + ar[pos + 1][0]);
    }
  }
  // not handle for bitmask == 7

  ret = max(ret, rek(pos + 1, sisak, 0));

  return ret;
}

int main(){
  scanf("%d%d", &n, &k);
  for(int i = 0;i < n; ++i){
    for(int j = 0;j < 3; ++j){
      scanf("%d", &ar[i][j]);
    }
  }

  printf("%lld\n", rek(0, k, 0));

  return 0;
}

/*
5 3
100 -9 -1
-1 3 2
-9 2 3
2 5 1
3 3 4
*/