#include <bits/stdc++.h>

using namespace std;

const long long eps = 1e-8;

bool same(double le, double ri) {
  return fabs(le-ri) < eps;
}

int main() {
  long long a, b, c, aa, bb, cc;
  scanf("%lld.%lld %lld.%lld %lld.%lld", &a, &aa, &b, &bb, &c, &cc);
  a = a * 100 + aa;
  b = b * 100 + bb;
  c = c * 100 + cc; 
  long long need = a * b + b * c + a * c, ri = a * b * c;
  need *= 100;
  puts((need < ri) ? "Yes" : "No");
  return 0;
}