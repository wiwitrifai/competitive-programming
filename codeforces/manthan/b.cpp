#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];
long long p, q, r;
int n;
long long le[N], ri[N];

int main() {
  scanf("%d %I64d %I64d %I64d", &n, &p, &q, &r);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", a+i);
  }
  for (int i = 0; i < n; i++) {
    le[i] = p * a[i];
    if (i)
      le[i] = max(le[i], le[i-1]);
  }
  for (int i = n-1; i >= 0; i--) {
    ri[i] = r * a[i];
    if (i+1 < n)
      ri[i] = max(ri[i], ri[i+1]);
  }
  long long ans = le[0] + q * a[0] + ri[0];
  for (int i = 0; i < n; i++) {
    ans = max(ans, le[i] + q * a[i] + ri[i]);
  }
  printf("%I64d\n", ans);
  return 0;
}