#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long sum = 0;
  int l, r, a;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    r = min(n, i+k), l = max(0, i-k+1);
    r -= k;
    r -= l-1;
    if (r < 0) r = 0;
    if (r)
      sum += ((long long)a) * r;
  }
  printf("%.8lf\n", (double)sum/(n-k+1));
  return 0;
}