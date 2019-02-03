#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
int ia[N], ib[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), ia[i] = i;
  for (int i = 0; i < m; ++i)
    scanf("%d", b+i), ib[i] = i;
  sort(ia, ia + n, [&](int x, int y) { return a[x] < a[y]; });
  sort(ib, ib + m, [&](int x, int y) { return b[x] < b[y]; });
  for (int i = 0; i < n; ++i)
    printf("%d %d\n", ia[i], ib[0]);
  for (int i = 1; i < m; ++i)
    printf("%d %d\n", ia[n-1], ib[i]);
  return 0;
}