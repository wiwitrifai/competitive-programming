#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, S = sqrt(N);
struct Bucket {
  int p[S], n, off = 0;
  int sorted[S];
  Bucket(int m) : n(m) {
    for (int i = 0; i < n; ++i)
      p[i] = 0;
    off = 0;
  }
  void add(int l, int r, int x) {
    r = min(r, n);
    if (x == 0) return;
    if (l == 0 && r == n) {
      off += x;
      return;
    }
    for (int j = l; j < r; ++j)
      p[j] += x;
    for (int j = 0; j < n; ++j) {
      sorted[j] = p[j];
    }
    sort(sorted, sorted+n);
  }
  int count(int x) {
    x -= off;
    return upper_bound(sorted, sorted+n, x) - lower_bound(sorted, sorted+n, x);
  }
};

int p[N];
Bucket * buck[N / S + 5];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
  }
  int s = 0;
  for (int i = 0; i < n; i += S) {
    int til = min(n, i+S);
    buck[s++] = new Bucket(til - i);
  }
  vector<int> decr;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int now = s;
    while (decr.size() > 0 && p[decr.back()] <= p[i]) {
      int val = p[i] - p[decr.back()];
      int r = decr.back() + 1;
      decr.pop_back();
      int l = decr.size() > 0 ? decr.back() + 1 : 0;
      now = min(now + 1, s);
      while (now * S >= r) -- now;
      while ((now + 1) * S > l) {
        buck[now]->add(max(l - now * S, 0), min(r - now * S, S), val);
        --now;
      }
    }
    decr.push_back(i);
    for (int j = 0; j < s; ++j) {
      ans += buck[j]->count(p[i]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
