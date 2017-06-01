#include <bits/stdc++.h>

using namespace std;

int a[6], b[6];

int main() {
  for (int i = 0; i < 5; i++)
    scanf("%d", a+i);
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    scanf("%d", b+i);
    ans += min(abs(a[i]-b[i]), 10 - abs(a[i]-b[i]));
  }
  printf("%d\n", ans);
  
  return 0;
}