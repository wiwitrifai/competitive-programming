#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    int ma = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", s+i);
      ma = max(ma, s[i]);
    }
    double le = 0, ri = ma;
    for (int it = 0; it < 100; ++it) {
      double mid = (le + ri) / 2;
      vector<double> vc;
      for (int i = 1; i <= n; ++i)
        vc.push_back((double)i * (s[i] - mid));
      sort(vc.begin(), vc.end());
      reverse(vc.begin(), vc.end());
      double sum = 0;
      for (int i = 0; i < x; ++i)
        sum += vc[i];
      if (sum >= 0)
        le = mid;
      else
        ri = mid;
    }
    printf("%.9lf\n", (le + ri) / 2);
  }
  return 0;
}