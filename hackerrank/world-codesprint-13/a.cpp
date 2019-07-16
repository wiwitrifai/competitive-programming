#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[x] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += a[i] == 0;
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i)
    if (a[i] == 0) {
      --ans;
      printf("%d%c", i, ans == 0 ? '\n' : ' ');
    }
  return 0;
}