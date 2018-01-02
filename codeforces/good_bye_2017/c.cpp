#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int x[N];
double y[N];

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; ++i) {
    scanf("%d", x+i);
    y[i] = r;
    for (int j = 0; j < i; ++j) {
      long long c = 2 * r, a = (x[i]-x[j]);
      a *= a;
      c *= c;
      if (c >= a) {
        y[i] = max(y[i], y[j] + sqrt(c - a));
      }
    }
  }
  for (int i = 0; i < n; ++i)
    printf("%.10lf%c", y[i], i == n-1 ? '\n' : ' ');
  return 0;
}