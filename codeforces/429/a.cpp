#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, a[N], b[N], c[N], ans[N];

bool cmp(int x, int y) {
  return b[x] > b[y];
}


int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i), c[i] = i;
  sort(c, c+n, cmp);
  sort(a, a+n);
  for (int i = 0; i < n; i++) {
    ans[c[i]] = a[i];
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", ans[i], (i == n-1) ? '\n' : ' ');
  }
  return 0;
}