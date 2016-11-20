#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long double eps = 1e-9;
long long a[N], sum[N];

int main() {
  int n;
  long long h;
  scanf("%d %lld", &n, &h);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a+i);
    sum[i] = a[i] + (i ? sum[i-1] : 0); 
  }
  long double tot = sum[n-1];
  long double ans = 1e20;
  for (int i = 0; i < n; i++) {
    long double A = (long double)n * n, B = (long double)(2 * i + 3) * n + tot * 2, C = (double) (1LL * (i+1) * (i+2) + (sum[i] - h) * 2);
    // cerr << "C : " << C << endl;
    if (C+eps >= 0.0) {
      ans = min(ans, (long double)i+1);
      // cerr << i+1 << endl;
    }
    else {
      long double cur = ceil((- B + sqrt(B * B - 4 * A * C)) / (2 * A));
      // cerr << cur << endl;
      // cerr << cur * n + i + 1 << " cuk " << endl;
      ans = min(ans, cur * n + i+1);
    }
  }
  cout << fixed << setprecision(0);
  cout << round(ans) << endl;
  return 0;
}