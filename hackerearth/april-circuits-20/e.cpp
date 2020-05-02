#include <bits/stdc++.h>

using namespace std;

int brute(int n) {
  int now = 0;
  vector<bool> vis(n, false);
  for (int i = 0; i < n-1; ++i) {
    vis[now] = true;
    while (vis[now]) now = (now + 1) % n;
    now = (now + 1) % n;
    while (vis[now]) now = (now + 1) % n;
  }
  return now;
}

int main() {
  int t;
  scanf("%d", &t);
  // for (int i = 1; i <= t; ++i) {
  //   cerr << i << " " << brute(i) << endl;
  // }
  while (t--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long now = (2 + k * 2) % n;
    long long cur = 1;
    while (cur * 2 < n) cur *= 2;
    long long ans = (now + (n - cur) * 2 - 1) % n;
    if (ans < 0)
      ans += n;
    if (ans == 0)
      ans = n;
    printf("%lld\n", ans);
  }
  return 0;
}
