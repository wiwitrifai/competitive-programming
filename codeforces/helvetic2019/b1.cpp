#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
long long sum[N];
pair<int, int> b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    b[i] = {x, y};
  }
  sort(b, b+m);
  sum[0] = 0;
  for (int i = 0; i < m; ++i)
    sum[i+1] = sum[i] + b[i].second;
  for (int i = 0; i < n; ++i) {
    int p = lower_bound(b, b+m, make_pair(a[i]+1, -1)) - b;
    printf("%lld%c", sum[p], i == n-1 ?'\n' : ' ');
  }

  return 0;
}
