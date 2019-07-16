#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
  int ans = 0;
  for (int i = 0; i < 3; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < 3; ++i) {
    int b;
    scanf("%d", &b);
    ans += max(b-a[i], 0);
  }
  printf("%d\n", ans);
  return 0;
}