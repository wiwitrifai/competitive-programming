#include <bits/stdc++.h>

using namespace std;

const int N = 3030;

vector<int> ans[N+N];

char s[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  int len = 0;
  int cnt = 0, offs = 0;
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      if (cnt == 0) continue;
      for (int j = 0; j < cnt; ++j) {
        ans[offs+j].push_back(i-j);
      }
      tot += cnt;
      len = max(len, offs+cnt);
      ++offs;
    }
    else {
      ++cnt;
      offs = max(0, offs-1);
    }
  }
  if (k < len || k > tot) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < len; ++i) {
    int sisa = len - i - 1;
    if ((int)ans[i].size() + sisa <= k) {
      for (int x : ans[i]) {
        printf("1 %d\n", x);
      }
      k -= (int)ans[i].size();
      continue;
    }
    int tepat = k - sisa;
    for (int j = 0; j < tepat-1; ++j) {
      printf("1 %d\n", ans[i][j]);
    }
    printf("%d", (int)ans[i].size() - (tepat-1));
    for (int j = tepat-1; j < (int)ans[i].size(); ++j) {
      printf(" %d", ans[i][j]);
    }
    printf("\n");
    k -= tepat;
  }
  return 0;
}
