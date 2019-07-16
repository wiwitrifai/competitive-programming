#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N], t[N];

int main() {
  scanf("%s %s", s, t);
  int n = strlen(s), m = strlen(t);
  int beda = 0;
  for (int i = 0; i + 1 < m; ++i)
    beda |= t[i] != t[i+1];
  if (beda) {
    puts("-1");
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += s[i] == t[0];
  }
  int sisa = n-cnt;
  int cur = 0;
  while (sisa > 0) {
    int b = min(cnt, m-1);
    cnt -= b;
    --sisa;
  }
  int ans = max(0, cnt - (m-1));
  printf("%d\n", ans);
  return 0;
}
