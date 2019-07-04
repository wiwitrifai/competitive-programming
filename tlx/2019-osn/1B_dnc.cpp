#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;

long long dp[N];
int n, s;

long long temp[N];

void dnc(vector<tuple<int, int, int>> & packets, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  vector<tuple<int, int, int>> lef, rig, cur;
  for (auto & it : packets) {
    int a, b, p;
    tie(a, b, p) = it;
    if (b <= mid)
      lef.push_back(it);
    else {
      rig.push_back(it);
      if (a <= mid)
        cur.push_back(it);
    }
  }
  dnc(lef, l, mid);
  long long mini = inf;
  for (int i = mid; i >= l; --i) {
    mini = min(mini, dp[i]);
    temp[i] = mini;
  }
  for (auto it : cur) {
    int a, b, p;
    tie(a, b, p) = it;
    dp[b] = min(dp[b], temp[max(a, l)] + p);
  }
  for (int i = mid + 1; i <= r; ++i)
    dp[i] = min(dp[i], dp[i-1] + s);
  dnc(rig, mid+1, r);
}

int main() {
  int m;
  scanf("%d %d %d", &n, &m, &s);
  vector<tuple<int, int, int>> packets(m);
  for (int i = 0; i < m; ++i) {
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);
    --a;
    packets[i] = {a, b, p};
  }
  for (int i = 0; i <= n; ++i)
    dp[i] = 1LL * i * s;
  dnc(packets, 0, n);
  printf("%lld\n", dp[n]);
  return 0;
}
