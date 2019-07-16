#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 4;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] != 1 && a[i+1] != 1) {
      puts("Infinite");
      return 0;
    }
    if (a[i] + a[i+1] - 1 == 2)
      ans += 3;
    else
      ans += 4;
  }
  for (int i = 0; i + 2 < n; ++i) {
    if (a[i] == 3 && a[i+2] == 2)
      --ans;
  }
  puts("Finite");
  printf("%d\n", ans);
  return 0;
}
