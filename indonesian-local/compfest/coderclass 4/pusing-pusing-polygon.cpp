#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    n *= k;
    printf("%.15lf\n", (double)n*tan(PI/n));
  }
  return 0;
}