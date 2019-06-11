#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N], t[N];

int main() {
  int n, k;
  scanf("%d", &k);
  scanf("%s %s", s, t);
  n = strlen(s);
  int same = 0;
  for (int i = 0; i < n; ++i) {
    same += s[i] == t[i];
  }
  int ambil = min(same, k);
  int ans = ambil;
  k -= ambil;
  int beda = n - same;
  ans += max(beda - k, 0);
  printf("%d\n", ans);
  return 0;
}
