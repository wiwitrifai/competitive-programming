#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e4 + 5;
 
int a[N];
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      int num;
      scanf("%d", &num);
      if(a[i] - a[i - 1] >= num) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
} 