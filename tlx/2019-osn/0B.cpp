#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int h[N], a[N], b[N];
int mask[N];
vector<int> price[4];

int main() {
  int n, p, q;
  scanf("%d %d %d", &n, &p, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", h+i);
  for (int i = 0; i < p; ++i) {
    scanf("%d", a+i);
    --a[i];
    mask[a[i]] |= 1;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d", b+i);
    --b[i];
    mask[b[i]] |= 2;
  }
  for (int i = 0; i < n; ++i) {
    price[mask[i]].push_back(h[i]);
  }
  sort(price[3].begin(), price[3].end());
  reverse(price[3].begin(), price[3].end());
  long long ans = 0;
  for (int i = 0; i < (int)price[3].size(); i += 2) {
    ans += price[3][i];
  }
  for (int x : price[1]) {
    ans += x;
  }
  printf("%lld\n", ans);
  return 0;
}
