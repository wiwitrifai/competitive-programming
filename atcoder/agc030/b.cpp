#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int x[N];

int main() {
  int len, n;
  scanf("%d %d", &len, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", x+i);
  }
  long long ans = 0, now = 0;
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    // cerr << l << " " << r << " : " << now << endl;
    int left = i, right = n-i-1;
    right = min(left+1, right);
    left = min(left, right);
    int le = i-left, ri = i+right;
    while (l < le) {
      now -= x[l]*2LL;
      ++l;
    }
    // cerr << l << " " << r << " : " << now << endl;
    r = max(r, i);
    while (r < ri) {
      ++r;
      now += (len - x[r]) * 2LL;
    }
    // cerr << l << " " << r << " : " << now << endl;
    // cerr << i << " " << le << " " << ri << " = " << now + x[i] << " " << now << endl;
    ans = max(ans, now + x[i]);
    if (i+1 < n) {
      now += x[i] * 2LL;
      if (r > i)
        now -= (len - x[i+1]) * 2LL;
    }
  }
  // cerr << ans << endl;
  l = r = 0;
  for (int i = 0; i < n; ++i) {
    int left = i, right = n-i-1;
    left = min(left, right+1);
    right = min(left, right);
    int le = i-left, ri = i+right;
    // cerr << l << " " << r << " : " << now << endl;
    while (l < le) {
      now -= x[l]*2LL;
      ++l;
    }
    // cerr << l << " " << r << " : " << now << endl;
    r = max(r, i);
    while (r < ri) {
      ++r;
      now += (len - x[r]) * 2LL;
    }
    // cerr << l << " " << r << " : " << now << endl;
    // cerr << i << " " << le << " " << ri << " = " << now + x[i] << " " << now << endl;
    ans = max(ans, now + len - x[i]);
    if (i+1 < n) {
      now += x[i] * 2LL;
      if (r > i)
        now -= (len - x[i+1]) * 2LL;
    }
  }
  printf("%lld\n", ans);
  return 0;
}