#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

long long ans[N];
long long off[N], sum[N];
int pos[N], cnt[N];

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  cnt[0] = n;
  for (int i = 0; i < w; ++i) {
    int m;
    scanf("%d", &m);
    while (m--) {
      int x;
      scanf("%d", &x);
      int p = pos[x];
      ans[x] -= 1LL * cnt[p+1] * (w - i);
      ans[x] += sum[p] - off[x];
      off[x] = sum[p+1];
      --cnt[p];
      ++cnt[p+1];
      ++pos[x];
      sum[p] += w-i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] += sum[pos[i]] - off[i];
    double mean = (long double)ans[i]/w + 1;
    printf("%.7lf\n", mean);
  }
  return 0;
}
