#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
typedef long long LL;
LL ar[N];
LL mins[N];
int n, k;

bool coba(int piv){
  int know = 1;
  for(int i = 0;i < piv; ++i) mins[i] = ar[i];
  int idx = 0;
  for(int i = piv; i < n; ++i){
    if((mins[idx] / 2) >= ar[i]){
      //printf("MASUK piv : %d, i : %d, idx : %d, %lld %lld\n", piv, i, idx, mins[idx], ar[i]);
      mins[idx] = ar[i];
      idx++;
      if(idx == piv) {
        idx = 0;
        know++;
      }
    }
  }
  return know >= k;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; ++tc){
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n; ++i) scanf("%lld", &ar[i]);
    sort(ar, ar + n);
    reverse(ar, ar + n);
    int l = 1;
    int r = n / k;
    int ans = 0;
    while(l <= r){
      int piv = (l + r) >> 1;
      if(coba(piv)){
        ans = piv;
        l = piv + 1;
      }
      else{
        r = piv - 1;
      }
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
