#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

bitset<N> s[2], r[2];

char b[N];
int ma[N+N];

int main() {
  for (int i = 0; i < 2; ++i) {
    s[i].reset();
    r[i].reset();
  }
  scanf("%s", b);
  int n = strlen(b);
  memset(ma, -1, sizeof ma);
  for (int i = 0; i < n; ++i) {
    b[i] -= '0';
    s[b[i]][i] = 1;
    r[b[i]][n-1-i] = 1;
  }
  for (int i = 1; i+1 < n; ++i) {
    int x = b[i];
    int selisih = (i - (n-1-i));
    int p;
    if (selisih < 0) {
      p = ((s[x]) & (r[x] >> (-selisih)))._Find_next(i) - i;
    }
    else {
      p = ((s[x] >> selisih) & (r[x]))._Find_next(n-i-1) - (n-i-1);
    }
    int batas = min(i, n-1-i);
    if (p > batas) continue;
    ma[i+p] = max(i-p, ma[i+p]);
  }
  long long ans = 0;
  for (int i = 0, cur = -1; i < n; ++i) {
    cur = max(cur, ma[i]);
    ans += cur+1;
  }
  printf("%lld\n", ans);
  return 0;
}
