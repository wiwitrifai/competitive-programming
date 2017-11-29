#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int l[N];
long long sum[N];
long long w, h;
long long cost[N], cost2[N];
int to[N], to2[N];

int main() {
  int n;
  scanf("%d %lld %lld", &n, &w, &h);
  sum[0] = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", l+i), sum[i+1] = sum[i] + l[i];
  long long r = (w / (sum[n] + n));
  long long now = (sum[n] + n) * r;
  if (now)
    now--, r *= n;
  else
    now = l[0], r = 1;
  while (now + l[r % n] + 1 <= w) now += l[r % n] + 1, r++;
  for (int i = 0; i < n; i++) {
    if (i == r) {
      now = l[i];
      r = i+1;
    }
    while (now + l[r % n] + 1 <= w) now += l[r % n] + 1, r++;
    to[i] = r % n;
    cost[i] = (i == 0) + (r-1)/n;
    now -= l[i];
    if (i+1 < r)
      now--;
  }
  int cur = 0;
  long long ans = 0;
  for (; h; h >>= 1) {
    if (h & 1) {
      ans += cost[cur];
      cur = to[cur];
    }
    for (int i = 0; i < n; i++) {
      to2[i] = to[to[i]];
      cost2[i] = cost[i] + cost[to[i]];
    }
    for (int i = 0; i < n; i++)
      to[i] = to2[i], cost[i] = cost2[i];
  }
  cout << ans << endl;
  return 0;
}