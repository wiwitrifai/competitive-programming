#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int ans[N];

int rec(int n) {
  if (n == 1)
    return 1;
  int & ret = ans[n];
  if (ret != -1)
    return ret;
  ret = 0;
  for (int i = 2; i < n; ++i) {
    if (rec(i) && rec(n-(i-1))) {
      return ret = 1;
    }
  }
  for (int i = 3; i < n; i += 2) {
    if (rec(n-i)) {
      return ret = 1;
    }
  }
  return ret;
}

void solve() {
  for (int i = 1, now = 0; now + i < N; i += 2) {
    now += i;
    ans[now] = 1;
  }
  int n;
  cin >> n;
  printf("%d\n", rec(n) ? 3 : 4);
}

int main() {
  memset(ans, -1, sizeof ans);
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
