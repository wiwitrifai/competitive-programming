#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ans[N];
int cnt[N];
int d[N];

int main() {
  int n;
  long long s;
  scanf("%d %lld", &n, &s);
  if (s < 2LL * (n-1) + 1 || s > 1LL * n * (n + 1) / 2) {
    puts("No");
    return 0;
  }
  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    long long low = 0;
    long long now = 1, unused = n, depth = 1;
    while (unused > 0) {
      long long rem = min(unused, now);
      unused -= rem;
      low += 1LL * rem * depth;
      now = now * mid;
      ++depth;
    }
    if (s < low)
      lo = mid + 1;
    else
      hi = mid;
  }
  int deg = lo;
  long long now = 1;
  int depth = 1;
  int unused = n;
  while (unused > 0) {
    int rem = unused;
    if (rem > now) rem = now;
    cnt[depth] = rem;
    unused -= rem;
    s -= 1LL * rem * depth;
    now = now * deg;
    ++depth;
  }
  cerr << " deg : " << deg << endl;
  // cerr << s << endl;
  int last = depth-1;
  while (s > 0) {
    while (last > 0 && cnt[last] <= 1) --last;
    int maju = depth - last;
    if (maju > s)
      maju = s;
    --cnt[last];
    ++cnt[last+maju];
    s -= maju;
    ++depth;
  }
  for (int i = 1, j = 1; i < depth; ++i) {
    for (int k = 0; k < cnt[i]; ++k)
      d[j++] = i;
  }
  assert(d[n] > 0);
  int cur = 0, pre = 1;
  // cerr << s << endl;
  puts("Yes");
  for (int i = 2; i <= n; ++i) {
    while (d[pre] < d[i]-1 || cur >= deg) {
      ++pre;
      cur = 0;
    }
    ++cur;
    printf("%d%c", pre, i == n ? '\n' : ' ');
  }
  return 0;
}