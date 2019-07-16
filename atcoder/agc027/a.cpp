#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N];

int main() {
  int x, n;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  int ans = 0;
  while (ans < n && x >= a[ans]) {
    x -= a[ans++];
  }
  if (ans == n && x != 0)
    --ans;
  printf("%d\n", ans);
  return 0;
}