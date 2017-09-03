#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int pre[N][2], suf[N][2], a[N]; 

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      pre[i][0] = pre[i][1] = a[i];
      suf[i][0] = suf[i][1] = a[i];
    }
    int ans = a[0];
    for (int len = 1; len < n; len++) {
      int loop = n-len;
      for (int i = 0; i < loop; i++) {
        int j = i + len;
        int dp0 = min(pre[i][1], suf[j][1]);
        int dp1 = max(pre[i][0], suf[j][0]);
        pre[i][0] = max(pre[i][0], dp0);
        suf[j][0] = max(suf[j][0], dp0);
        suf[j][1] = min(suf[j][1], dp1);
        pre[i][1] = min(pre[i][1], dp1);
        ans = dp0;
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}