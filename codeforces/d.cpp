#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e17;

int a[N], b[N];
long long dp[N];
vector< pair< long long, long long > > cht;

bool is_bad(pair<long long, long long> x, pair<long long, long long> y, pair<long long, long long> z) {
  return (y.first - z.first) * (y.second - x.second) >= (x.first - y.first) * (z.second - y.second);
}

long long get(pair<long long, long long > p, long long x) {
  return x * p.first + p.second;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i  < n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b+i);
  }
  dp[0] = 0;
  cht.push_back({b[0], dp[0]});
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j+1 < cht.size() && get(cht[j], a[i]) >= get*(cht[j+1], a[i])) j++;
    dp[i] = get(cht[j], a[i]);
    pair< long long, long long > now = {b[i], dp[i]};
    while (cht.size() > 1 && is_bad(cht[(int)cht.size() - 2]), cht.back(), now) cht.pop_back();
    cht.push_back(now);
  }
  printf("%lld\n", dp[n-1]);
  return 0;
}