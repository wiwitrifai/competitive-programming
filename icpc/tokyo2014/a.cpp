#include <bits/stdc++.h>

using namespace std;
const int N = 15;
int n, m;
int ar[N + 5];
int br[N + 5];
int cntA[2];
int cntB[2];

int ARR[N + 5];
int BRR[N + 5];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0;i < n; ++i) {
    scanf("%d", &ar[i]);
    cntA[ar[i]]++;
  }
  int last = 0;
  for(int i = 0;i < m; ++i){
    scanf("%d", &br[i]);
    cntB[i&1] += br[i];
    for(int j = 0;j < br[i]; ++j){
      ARR[last + j] = i & 1;
      BRR[last + j] = !(i & 1);
    }
    last += br[i];
  }
  int ans = 0;
  if(cntA[0] != cntA[1]){
    if(cntA[0] == cntB[0]){ // diawali dengan 0
      int idxA = 0, idxArr = 0;
      for(int i = 0;i < cntA[0]; ++i){
        while(ar[idxA] != 0) idxA++;
        while(ARR[idxArr] != 0) idxArr++;
        ans += abs(idxA - idxArr);
        idxA++;
        idxArr++;
      }
    }
    else{ // diawali dengan 1
      int idxB = 0, idxBrr = 0;
      for(int i = 0;i < cntA[1]; ++i){
        while(ar[idxB] == 0) idxB++;
        while(BRR[idxBrr] == 0) idxBrr++;
        ans += abs(idxB - idxBrr);
        idxB++;
        idxBrr++;
      }
    }
  }
  else{
    int ansA = 0, ansB = 0;
    int idxA = 0, idxArr = 0;
    //for(int i = 0;i < n; ++i) printf("%d ", ARR[i]); puts("");
   // for(int i = 0;i < n; ++i) printf("%d ", BRR[i]); puts("");
    
    for(int i = 0;i < cntA[0]; ++i){
      while(ar[idxA] != 0) idxA++;
      while(ARR[idxArr] != 0) idxArr++;
      ansA += abs(idxA - idxArr);
      idxA++;
      idxArr++;
    }
    int idxB = 0, idxBrr = 0;
    for(int i = 0;i < cntA[1]; ++i){
      while(ar[idxB] == 0) idxB++;
      while(BRR[idxBrr] == 0) idxBrr++;
      ansB += abs(idxB - idxBrr);
      idxB++;
      idxBrr++;
    }
    ans = min(ansA, ansB);
  }
  cout << ans << endl;
  
  return 0;
}