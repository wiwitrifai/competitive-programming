#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for(int i = 0; i<n; i++) {
    int a;
    scanf("%d", &a);
    cnt += a;
  }  
  if(n == 1) {
    puts(cnt ? "YES" : "NO");
  }
  else {
    puts(n == cnt+1 ? "YES" : "NO");
  }
  return 0;
}