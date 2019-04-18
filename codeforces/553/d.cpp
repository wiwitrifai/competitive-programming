#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
int id[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d %d", a+i, b+i), id[i] = i;
  sort(id, id+n, [](int l, int r) { return b[l]-a[l] < b[r]-a[r]; });
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = id[i];
    ans += 1LL * i * a[x];
    ans += 1LL * (n - i - 1) * b[x];
  }
  printf("%lld\n", ans);
  return 0;
}
