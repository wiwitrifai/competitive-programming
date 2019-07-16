#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int le[N], ri[N];
char buf[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    int len = strlen(buf);
    int cnt = 0;
    for (int j = 0; j < len; ++j)
      cnt += buf[j] == '(' ? +1 : -1;
    bool ok = 1;
    if (cnt >= 0) {
      int cur = 0;
      for (int j = 0; j < len; ++j) {
        cur += buf[j] == '(' ? +1 : -1;
        if (cur < 0) {
          ok = 0;
          break;
        }
      }
    }
    else {
      int cur = 0;
      for (int j = len-1; j >= 0; --j) {
        cur += buf[j] == '(' ? +1 : -1;
        if (cur > 0) {
          ok = 0;
          break;
        }
      }
    }
    if (!ok)
      continue;
    if (cnt >= 0)
      ++le[cnt];
    else
      ++ri[-cnt];
  }
  int ans = le[0] / 2;
  for (int i = 1; i < N; ++i) {
    ans += min(le[i], ri[i]);
  }
  printf("%d\n", ans);
  return 0;
}