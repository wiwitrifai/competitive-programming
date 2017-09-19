#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ma[N];
long long sum[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int last = 0;
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    ma[i] = max(a[i], last+1);
    cur += ma[i] - a[i];
    sum[i] = cur;
    last = ma[i];
  }
  last = 0;
  cur = 0;
  for (int i = n-1; i >= 0; i--) {
    int wa = max(ma[i], last+1);
    sum[i] += cur + wa - ma[i];
    last = max(a[i], last+1);
    cur += last - a[i];
  }
  long long ans = sum[0];
  for (int i = 0; i < n; i++) {
    ans = min(ans, sum[i]);
  }
  cout << ans << endl;
  return 0;
}