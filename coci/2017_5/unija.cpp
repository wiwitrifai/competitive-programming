#include <bits/stdc++.h>

using namespace std;

const int N  = 1e6 + 6;

pair< int, int > rec[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    rec[i] = make_pair(x, y);
  }
  sort(rec, rec+n);
  int y = rec[n-1].second;
  int now = rec[n-1].first;
  long long ans = 0;
  for (int i = n-1; i >= 0; i--) {
    ans += 1LL * y * (now - rec[i].first);
    now = rec[i].first;
    if (y < rec[i].second) y = rec[i].second;
  }
  ans += 1LL * y * now;
  printf("%lld\n", ans);
  return 0;
}