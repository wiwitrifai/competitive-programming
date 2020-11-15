#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int x[N];
long long sum[N], add[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", x+i);
  }
  sort(x, x+n);
  sum[0] = 0, add[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i+1] = sum[i] + abs(x[i]);
    add[i+1] = add[i] + x[i];
  }
  long long ans = sum[n];
  for (int len = 0; len <= n; ++len) {
    int l = 0, r = l + len - 1;
    int a = r+2, b = a + len - 1;
    if (b >= n) break;
    long long cur = (add[b+1] - add[a]) - (add[r+1] - add[l]) + sum[n] - sum[b+1];
    // cerr << len << " " << cur << endl;
    ans = min(ans, cur);
  }
  for (int len = 1; len <= n; ++len) {
    int l = 0, r = l + len - 1;
    int a = r+1, b = a + len - 1;
    if (b >= n) break;
    long long cur = (add[b+1] - add[a]) - (add[r+1] - add[l]) + sum[n] - sum[b+1];
    // cerr << len << " " << cur << endl;
    ans = min(ans, cur);
  }
  for (int len = 0; len <= n; ++len) {
    int b = n-1, a = b - len + 1;
    int r = a - 2, l = r - len + 1;
    if (l < 0) break;
    long long cur = (add[b+1] - add[a]) - (add[r+1] - add[l]) + sum[l];
    // cerr << len << " " << cur << endl;
    ans = min(ans, cur);
  }
  for (int len = 1; len <= n; ++len) {
    int b = n-1, a = b - len + 1;
    int r = a - 1, l = r - len + 1;
    if (l < 0) break;
    long long cur = (add[b+1] - add[a]) - (add[r+1] - add[l]) + sum[l];
    // cerr << len << " " << cur << endl;
    ans = min(ans, cur);
  }
  printf("%lld\n", ans);
  return 0;
}
