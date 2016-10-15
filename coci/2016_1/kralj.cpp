#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], p[N], v[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", p+i);
  for (int i = 0; i < n; i++)
    scanf("%d", v+i);
  int ans = 0;
  sort(p, p+n);
  sort(v, v+n);
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && v[j] < p[i]) j++;
    if (j == n)
      break;
    ans++;
    j++;
  }
  printf("%d\n", ans);
  return 0;
}