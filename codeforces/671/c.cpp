#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x;
  scanf("%d %d", &n, &x);
  vector<int> a(n);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    cnt += a[i] == x;
  }
  if (cnt == n) {
    puts("0");
    return;
  }
  long long sum = 0;
  for (int z : a)
    sum += z;
  if (cnt > 0 || sum == 1LL * n * x) {
    puts("1");
    return;
  }
  puts("2");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
