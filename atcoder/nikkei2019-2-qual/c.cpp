#include <bits/stdc++.h>

using namespace std;

vector<int> GetPos(vector<int> & a) {
  vector<int> pos(a.size());
  iota(pos.begin(), pos.end(), 0);
  sort(pos.begin(), pos.end(), [&](int l, int r) {
    return a[l] < a[r];
  });
  return pos;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  bool ok = 1;
  vector<int> pa = GetPos(a), pb = GetPos(b);
  for (int i = 0; i < n; ++i) {
    ok &= a[pa[i]] <= b[pb[i]];
  }
  if (!ok) {
    puts("No");
    return 0;
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (a[pa[i+1]] <= b[pb[i]]) {
      puts("Yes");
      return 0;
    }
  }
  vector<int> to(n);
  for (int i = 0; i < n; ++i)
    to[pa[i]] = pb[i];
  int now = to[0], cnt = 1;
  while (now) {
    ++cnt;
    now = to[now];
  }
  puts(cnt < n ? "Yes" : "No");
  return 0;
}
