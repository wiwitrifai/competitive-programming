#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
const int N = 50000, INF = 1e9;

int w, n;
int ar[N + 5];
int dp[N + 5];
int pref[N + 5];

bool cari(int x){
  dp[n] = 1;
  int poikiri = n, poikanan = n;
  int poimin = n, poimax = n;
  int cntnotINF = 0;
  for(int i = n - 1; i > 0; --i){
    if(pref[n] - pref[i - 1] + n - i <= w) dp[i] = 1;
    else{ 
      while(poimin >= i && pref[poimin] - pref[i - 1] + 1LL * (poimin - i) * x > 1LL * w) poimin--;
      while(poimax >= i && pref[poimax] - pref[i - 1] + (poimax - i) > w) poimax--;
      
      int min_now = poimin;
      int max_now = poimax;
      if(pref[min_now] - pref[i - 1] + 1LL * (min_now - i) * x < 1LL * w){
        if(pref[min_now + 1] - pref[i - 1] + (min_now + 1 - i) > w) min_now = INF;
        else min_now++;
      }
      if((w - pref[max_now] + pref[i - 1] + x - 1) / x > max_now - i) max_now = INF;
      //printf("SEBELUM %d %d %d %d %d\n", min_now, max_now, poikiri, poikanan, cntnotINF);
      if(min_now == INF || max_now == INF || min_now > max_now) dp[i] = INF;
      else{
        min_now++;
        max_now++;
        if(max_now < poikiri){
          poikiri = max_now, poikanan = max_now;
          cntnotINF = 0;
        }
        else{
          while(poikanan > max_now){
            if(dp[poikanan] != INF) cntnotINF--;
            poikanan--;
          }
        }
        while(poikiri >= min_now){
          if(dp[poikiri] != INF) cntnotINF++;
          poikiri--;
        }
        dp[i] = (cntnotINF != 0) ? 1 : INF;
       // printf("MASUK X : %d, i : %d , mini : %d, maks : %d, dp[%d] : %d\n", x, i, min_now, max_now, i, dp[i]);
       
      }
      //printf("SESUDAH %d %d %d %d %d\n", min_now, max_now, poikiri, poikanan, cntnotINF);
      //printf("dp[%d] : %d\n", i, dp[i]);
    }
  }
  return dp[1] != INF;
}

int main(){
  while(scanf("%d%d", &w, &n), w > 0 || n > 0){
    int mini = 1;
    int maks = w;
    pref[0] = 0;
    for(int i = 1;i <= n; ++i){
      scanf("%d", &ar[i]);
      pref[i] = pref[i - 1] + ar[i];
      maks = min(maks, w - ar[i]);
    }
    int ans = maks;
    while(mini <= maks){
      int piv = (mini + maks) >> 1;
      if(cari(piv)){
        ans = piv;
        maks = piv - 1;
      }
      else{
        mini = piv + 1;
      }
    }
    
    printf("%d\n", ans);
  }
  return 0;
}