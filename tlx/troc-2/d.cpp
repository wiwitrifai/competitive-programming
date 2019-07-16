#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;

void generate(int n, int a, int p, int m, int * cnt) {
  vector<int> seq;
  seq.push_back(a);
  ++cnt[a];
  for (int i = 1; i < n; ++i) {
    a = 1LL * a * p % m;
    if (cnt[a]) {
      break;
    }
    seq.push_back(a);
    ++cnt[a];
  }
  if (seq.size() == n)
    return;
  int off = 0;
  while (off < seq.size() && seq[off] != a) ++off;
  int cyc = (int)seq.size() - off;
  for (int i = off; i < seq.size(); ++i) {
    int sisa = n - i - 1;
    if (sisa <= 0) break;
    cnt[seq[i]] += sisa / cyc;
  }
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    sum += cnt[i];
  }
  assert(sum == n);
}

int a[N], b[N];

int main() {
  int n, x, y, c, d, ma, mb;
  scanf("%d %d %d %d %d %d %d", &n, &x, &y, &c, &d, &ma, &mb);
  generate(n, x, c, ma, a);
  generate(n, y, d, mb, b);
  int i = 0, j = 0;
  long long ans = 0;
  while (i < ma && j < mb) {
    while (a[i] == 0 && i < ma) ++i;
    while (b[j] == 0 && j < mb) ++j;
    if (i < ma && j < mb) {
      int mi = min(a[i], b[j]);
      ans += 1LL * mi * i * j;
      a[i] -= mi;
      b[j] -= mi;
    }
  }
  printf("%lld\n", ans);
  return 0;
}