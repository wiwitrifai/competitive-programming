#include <bits/stdc++.h>

using namespace std;



int main() {
  int a[4];
  for (int i = 0; i < 3; ++i)
    scanf("%d", a+i); 
  int ans = -1;
  for (int i = 2; i <= 100; ++i) {
    bool ok = 1;
    for (int j = 0; j < 3; ++j) {
      if (i % a[j]) continue;
      ok = 0;
    }
    if (ok) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}