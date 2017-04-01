#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
const long long inf = 1e16;
int a[N];
long long sum[2], mi[2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  sum[0] = sum[1] = 0;
  mi[0] = 0;
  long long ans = a[1]-a[0];
  for (int i = 0; i + 1 < n; i++) {
    int cur = abs(a[i+1]-a[i]);
    if (i & 1) {
      sum[1] += cur;
      sum[0] -= cur;
    }
    else {
      sum[0] += cur;
      sum[1] -= cur;
    }
    long long now = -inf;
    now = max(sum[0]-mi[0], sum[1]-mi[1]);
    ans = max(ans, now);
    if (i & 1)
      mi[0] = min(mi[0], sum[0]);
    else
      mi[1] = min(mi[1], sum[1]);
  }
  cout << ans << endl;
  return 0;
}