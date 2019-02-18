#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int big = *max_element(a, a+n);
  int cnt =0, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == big)
      ++cnt;
    else
      cnt = 0;
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}