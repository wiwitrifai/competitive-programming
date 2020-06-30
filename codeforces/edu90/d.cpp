#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

long long max_prefix(vector<int>& b) {
  long long lowest = 0, cur = 0, ans = 0;
  for (int x : b) {
    cur += x;
    ans = max(ans, cur - lowest);
    lowest = min(lowest, cur);
  }
  return ans;
}

void solve() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if ((i & 1) == 0)
      ans += a[i];
  }
  vector<int> p, q;
  for (int i = 0; i+1 < n; ++i) {
    if (i & 1) {
      p.push_back(a[i] - a[i+1]);
    } else {
      q.push_back(a[i+1] - a[i]);
    }
  }
  ans += max(max_prefix(p), max_prefix(q));
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
