#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int up[N];
int t[N], l[N], r[N];
int ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", t+i, l+i, r+i);
    --l[i], --r[i];
    if (t[i] == 1) {
      for (int j = l[i]; j < r[i]; ++j) {
        up[j] = 1;
      }
    }
  }
  bool ok = 1;
  for (int i = 0; i < m; ++i) {
    if (t[i] == 0) {
      ok = 0;
      for (int j = l[i]; j < r[i]; ++j) {
        if (!up[j])
          ok = 1;
      }
      if (!ok)
        break;
    }
  }
  if (!ok) {
    puts("NO");
    return 0;
  }
  ans[0] = 0;
  int mins = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (up[i])
      ans[i+1] = ans[i] + 1;
    else
      ans[i+1] = ans[i] - 1;
    mins = min(mins, ans[i+1]);
  }
  for (int i = 0; i < n; ++i)
    ans[i] += 1 - mins;
  puts("YES");
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  return 0;
}
