#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a+i);
  int ans = 0;
  for (int i = 0; i < n-1; i++)
    ans += ((a[i] &1) == (a[i+1] & 1));
  printf("%d\n", ans);
  return 0;
}