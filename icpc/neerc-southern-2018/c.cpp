#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long cnt[N + 5];
long long sum[N + 5];

void upd_cnt(int x, long long v) {
  for (; x < N; x += x&-x)
    cnt[x] += v;
}
void upd_sum(int x, long long v) {
  for (; x < N; x += x&-x)
    sum[x] += v;
}
int find(long long v) {
  int x = 0;
  for (int i = 20; i >= 0; --i) {
    int now = x + (1 << i);
    if (now >= N) continue;
    if (cnt[now] > v) continue;
    v -= cnt[now];
    x = now;
  }
  return x;
}
long long get_cnt(int x) {
  long long v = 0;
  for (; x; x -= x&-x)
    v += cnt[x];
  return v;
}
long long get_sum(int x) {
  long long v = 0;
  for (; x; x -= x&-x)
    v += sum[x];
  return v;
}

long long a[N];

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  vector<tuple<int, int, int> > event;
  for (int i = 0; i < m; ++i) {
    int l, r, c, p;
    scanf("%d %d %d %d", &l, &r, &c, &p);
    event.emplace_back(l, c, p);
    event.emplace_back(r+1, -c, p);
  }
  sort(event.begin(), event.end());
  long long ans = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < event.size() && get<0>(event[j]) <= i) {
      int c, p;
      tie(ignore, c, p) = event[j];
      upd_cnt(p, c);
      upd_sum(p, 1LL * c * p);
      a[p] += c;
      ++j;
    }
    int x = find(k);
    long long sisa = k - get_cnt(x);
    ans += get_sum(x) + 1LL * min(sisa, a[x+1]) * (x+1);
  }
  printf("%lld\n", ans);
  return 0;
}