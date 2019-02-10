#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
long long dpl[N][3], dpr[N][3];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n; ++i) {
    dpl[i+1][0] = dpl[i][0] + a[i];
    int cost = a[i] == 0 ? 2 : (a[i] & 1);
    dpl[i+1][1] = cost + min(dpl[i][0], dpl[i][1]);
    cost = (a[i] & 1) ? 0 : 1;
    dpl[i+1][2] = cost + min(dpl[i][0], min(dpl[i][1], dpl[i][2]));
    for (int j = 0; j < 2; ++j)
      dpl[i+1][j+1] = min(dpl[i+1][j], dpl[i+1][j+1]);
  }
  for (int i = n-1; i >= 0; --i) {
    dpr[i][0] = dpr[i+1][0] + a[i];
    int cost = a[i] == 0 ? 2 : (a[i] & 1);
    dpr[i][1] = cost + dpr[i+1][1];
    cost = (a[i] & 1) ? 0 : 1;
    dpr[i][2] = cost + dpr[i+1][2];
    for (int j = 0; j < 2; ++j)
      dpr[i][j+1] = min(dpr[i][j], dpr[i][j+1]);
  }
  long long ans = 1e18;
  for (int i = 0; i <= n; ++i) {
    // cerr << i << " " << dpl[i][2] << " " << dpr[i][2] << endl;
    ans = min(ans, dpl[i][2] + dpr[i][2]);
  }
  printf("%lld\n", ans);
  return 0;
}