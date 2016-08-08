#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int pre[202][N];
int a[202];
char sol[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i<n; i++) {
      scanf("%d", a+i);
      sum += a[i];
    }
    int ssum = sum;
    sum /= 2;
    pre[0][0] = 0;
    for(int i = 1; i<= sum; i++)
      pre[0][i] = -1;
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<=sum; j++) {
        pre[i+1][j] = -1;
        if(pre[i][j] >= 0)
          pre[i+1][j] = j;
        if(a[i] <= j && pre[i][j-a[i]] >= 0)
          pre[i+1][j] = j-a[i];
      }
    }
    int ans = 0;
    for(int i = sum; i>=0; i--) if(pre[n][i] != -1){
      ans = i;
      break;
    }
    printf("%lld\n", 1LL*ans * (ssum-ans));
    sol[n] = '\0';
    for(int i = n; i>0; i--) {
      sol[i-1] = ((pre[i][ans] == ans) ? 'R' : 'D');
      ans = pre[i][ans];
    }
    printf("%s\n", sol);
  }
  return 0;
}