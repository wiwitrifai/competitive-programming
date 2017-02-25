#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, LN = 19, inf = 1e9 + 7;

int n;
pair< pair< int, int >, int > ring[N];
long long sp[LN][N];
long long  get(int l, int r) {
  int len = r-l + 1;
  if (len <= 0) return 0;
  int lg = 31 - __builtin_clz(len);
  return max(sp[lg][r], sp[lg][l+(1<<lg)-1]);
}
void upd(int x, long long val) {
  sp[0][x] = val;
  for (int i = 0; x - (1<<i) >= 0 && i + 1 < LN; i++)
    sp[i+1][x] = max(sp[i][x], sp[i][x - (1<<i)]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, h;
    scanf("%d %d %d", &a, &b, &h);
    ring[i] = {{b, a}, h};
  }
  sort(ring, ring + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int id = lower_bound(ring, ring+n, make_pair(make_pair(ring[i].first.second, inf), inf)) - ring;
    long long now = get(id, i-1) + ring[i].second;
    upd(i, now);
    ans = max(ans, now);
  }
  cout << ans << "\n";
  return 0;
}