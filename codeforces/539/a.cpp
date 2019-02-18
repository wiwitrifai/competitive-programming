#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 21;

int cnt[2][N];

int main() {
  int n;
  scanf("%d", &n);
  int x = 0, c = 0;
  cnt[c][0] = 1;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    x ^= a;
    c = !c;
    ans += cnt[c][x];
    ++cnt[c][x];
  }
  printf("%lld\n", ans);
  return 0;
}