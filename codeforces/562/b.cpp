#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char b[N];
int ma[N+N];

int main() {
  scanf("%s", b);
  int n = strlen(b);
  memset(ma, -1, sizeof ma);
  for (int i = 0; i < n; ++i) {
    b[i] -= '0';
  }
  for (int i = 1; i+1 < n; ++i) {
    int p = 1;
    int batas = min(i, n-1-i);
    while (p <= batas && (b[i-p] != b[i] || b[i+p] != b[i])) ++p;
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
