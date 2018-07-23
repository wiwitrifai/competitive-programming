#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];

int cntl[N], cntr[N];

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s);
    bool le = 1, ri = 1;
    int cur = 0;
    for (int j = 0; j < len; ++j) {
      cur += s[j] == '(' ? +1 : -1;
      if (cur < 0) le = 0;
    }
    cur = 0;
    for (int j = len-1; j >= 0; --j) {
      cur += s[j] == '(' ? -1 : +1;
      if (cur < 0) ri = 0;
    }
    if (le && ri && cur == 0) {
      ans += cntl[0] + cntr[0]+1;
      ++cntl[0];
      ++cntr[0];
    }
    else {
      if (le) {
        ans += cntr[-cur];
        ++cntl[-cur];
      }
      if (ri) {
        ans += cntl[cur];
        ++cntr[cur];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}