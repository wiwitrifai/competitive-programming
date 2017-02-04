#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int a[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  int ans = 0;
  for (int i = n-1; i >= 0 ; i--) {
    if (ans + 1 <= a[i])
      ans++;
    else
      break;
  }
  printf("%d\n", ans);
  return 0;
}