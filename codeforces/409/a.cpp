#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
int a[N], b[N], p, n;

int main() {
  scanf("%d %d", &n, &p);
  long long suma = 0, sumb = 0;
  for (int i = 0; i < n; i++)
    scanf("%d %d", a+i, b+i), suma += a[i], sumb += b[i];
  if (suma <= p)
    puts("-1");
  else {
    double l = 0, r = (double)sumb/(suma-p);
    for (int iter = 0; iter < 200; iter++) {
      double mid = (l + r)/2;
      double need = 0;
      for (int i = 0; i < n; i++) {
        double cur = ((double)a[i] * mid - b[i])/(double)p;
        if (cur < 0) cur = 0;
        need += cur;
      }
      if (need <= mid)
        l = mid;
      else
        r = mid;
    }
    cerr << l << " " << r << endl;
    printf("%.10lf\n", l);
  }
  return 0;
}