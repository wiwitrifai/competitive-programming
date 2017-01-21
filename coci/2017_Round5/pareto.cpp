#include <bits/stdc++.h>

using  namespace std;

const int N = 3e6 + 6;
long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a+i);
    sum += a[i];
  }
  sort(a, a+n);
  long long tmp = 0;
  double diff = 0, cl = 0, mon = 0;
  for (int i = n-1; i >= 0; i--) {
    tmp += a[i];
    double tcl = (double) (n-i) * 100/n;
    double tmon = (double) tmp * 100/ sum;
    if (diff < tmon - tcl) {
      diff = tmon - tcl;
      mon = tmon;
      cl = tcl;
    }
  }
  printf("%.14lf\n%.14lf\n", cl, mon);

  return 0;
}