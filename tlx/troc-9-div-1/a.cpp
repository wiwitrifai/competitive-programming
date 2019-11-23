#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  vector<int> all;
  int w = k / 2;
  for (int i = 0; i < w; ++i)
    all.push_back(a[i]);
  for (int i = 0; i < k - w; ++i) {
    all.push_back(a[n-1-i]);
  }
  sort(all.begin(), all.end());
  long long tot = 0, ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += 1LL * i * all[i] - tot;
    tot += all[i];
  }
  printf("%lld\n", ans);
  return 0;
}
