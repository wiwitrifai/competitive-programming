#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], p[N];

int main() {
  int n;
  scanf("%d", &n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    p[x] = p[x-1] + 1;
    m = max(m, p[x]);
  }
  printf("%d\n", n-m);
  return 0;
}