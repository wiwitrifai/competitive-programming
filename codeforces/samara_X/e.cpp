#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

long long t[N], b[N];
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%I64d", t+i);
  for (int i = 0; i < m; i++)
    scanf("%I64d", b+i);
  long long last = 0;
  long long ans = 0;
  int j = 0;
  if (b[0] < t[0])
    ans += 2LL * (t[0]-b[0]);
  if (b[m-1] > t[n-1])
    ans += 2LL * (b[m-1] - t[n-1]);
  for (int i = 0, j = 0; i+1 < n; i++) {
    last = t[i];
    long long ma = 0;
    while (j < m && b[j] <= t[i]) j++;
    while (j < m && b[j] <= t[i+1]) {
      ma = max(b[j]-last, ma);
      last = b[j++];
    }
    ma = max(t[i+1]-last, ma);
    ans += min(2LL * (t[i+1]-t[i]-ma), (long long)(t[i+1]-t[i]));
  }
  cout << ans << endl;
  return 0;
}