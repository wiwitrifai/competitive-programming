// salah paham soal

#include <bits/stdc++.h>

using namespace std;

const int N = 4048;

struct fen {
  long long bit[N];
  void reset() {
    memset(bit, 0, sizeof bit);
  }
  long long get(int x) {
    ++x;
    long long ret = 0;
    for (; x; x -= x&-x)
      ret = max(ret, bit[x]);
    return ret;
  }
  void upd(int x, long long v) {
    ++x;
    for (; x < N; x += x&-x)
      bit[x] = max(bit[x], v);
  }
};

fen fa, fb;
int c[N], d[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    for (int i = 0; i < n; ++i)
      scanf("%d", c+i);
    for (int i = 0; i < n; ++i)
      scanf("%d", r+i);
    for (int i = 0; i + 1 < n; ++i)
      scanf("%d", d+i);
    long long ans = r[0] - c[0];
    for (int i = 0; i < n; ++i) {
      fa.reset();
      fb.reset();
      long long now = 0;
      long long dist = 0;
      for (int j = i+1; j < n; ++j) {
        if (d[j-1] > l) break;
        dist += d[j-1];
        now += r[j] - d[j-1];
        fa.upd(j, now);
        fb.upd(j, now - dist);
      }
      now = r[i] - c[i];
      dist = 0;
      for (int j = i; j >= 0; --j) {
        int to = min(j + k -1, n-1);
        if (to < i) break;
        ans = max(ans, now + fb.get(to));
        ans = max(ans, now - dist + fa.get(to));
        if (j > 0) {
          if (d[j-1] > l) break;
          dist += d[j-1];
          now += r[j-1] - d[j-1];
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}