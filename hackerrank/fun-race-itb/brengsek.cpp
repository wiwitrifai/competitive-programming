#include <bits/stdc++.h>

using namespace std;

int a[1024];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i  < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > x)
      break;
    ans++;
    x -= a[i];
  }
  printf("%d\n", ans);

  return 0;
}