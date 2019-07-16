#include <bits/stdc++.h>

using namespace std;

const int N = 333;

int f[N], l[N];

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", f+i, l+i);
  }
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    if (f[i] == 0) continue;
    int sum = 0;
    for (int j = i; j < n && f[j]; ++j) {
      sum += l[j];
    }
    if (sum >= w) {
      ans = i+1;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}