#include <bits/stdc++.h>

using namespace std;
long long a = 1, k = 2, x, dy;
long long A = a * a - k * k, B, C;
long double calc(long double t) {
  return A * t * t + B * t + C;
}

const long double eps = 1e-7;

int main() {
  srand(time(0));
  for (a = 1; a <= 100; ++a) {
    cerr << "start a :" << a << endl;
    for (k = a+1; k < 100; ++k) {
      A = a * a - k * k;
      for (x = 1; x < 10000; ++x) {
        B = 2LL * k * x;
        long double t1 = -(long double)(B/2)/A;
        for (dy = max((long long)(t1 * a+1), 2LL); dy < 10000; ++dy) {
          C = - (x * x + dy * dy);
          long double t2 = (long double)dy/a;
          if (calc(t1) > -eps && calc(t2) < -eps) {
            cerr << t1 << " " << t2 << endl;
            cerr << calc(t1) << " " << calc(t2) << endl;
            cerr << a << " " << k << " " << x << " " << dy << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}