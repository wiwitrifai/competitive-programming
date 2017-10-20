#include <bits/stdc++.h>
using namespace std;
const int N = 50;

struct matrix{
   int n, m;
   int ar[N + 1][N + 1];
    matrix(int n = 0, int m = 0) : n(n), m(m) {
      
    }
};

int n, m, a, b, c, t;
matrix mult(const matrix &a, const matrix &b){
   matrix ans(a.n, b.m);
   for(int i = 0;i < ans.n; ++i){
     for(int j = 0;j < ans.m; ++j){
       ans.ar[i][j] = 0;
       for(int k = 0;k < a.m; ++k){
         ans.ar[i][j] += a.ar[i][k] * b.ar[k][j];
       }
       if(ans.ar[i][j] >= m) ans.ar[i][j] %= m;
     }
   }
   return ans;
}
int ar[N + 5];
int main(){
  while(scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &c, &t), (n > 0  || m > 0 || a > 0 || b > 0 || c > 0 || t > 0)){
    matrix jawab(n, 1);
    for(int i = 0; i < n; ++i) scanf("%d", &ar[i]), jawab.ar[i][0] = ar[i]; 
    matrix mults(n, n);
    for(int i = 0;i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(j == i - 1) mults.ar[i][j] = a;
        else if(j == i) mults.ar[i][j] = b;
        else if(j == i + 1) mults.ar[i][j] = c;
        else mults.ar[i][j] = 0;
      }
    }
    int tnow = t;
    int lastidx = 1;
    while(tnow > 0){
       int last = __builtin_ffs(tnow);
       while(lastidx < last){
          mults = mult(mults, mults);
          lastidx++;
       }
       jawab = mult(mults, jawab);
       tnow ^= (tnow & -tnow);
    }
    
    for(int i = 0;i < n; ++i) printf("%d%c", jawab.ar[i][0], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}