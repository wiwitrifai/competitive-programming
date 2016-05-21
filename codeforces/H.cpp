#include <bits/stdc++.h>

using namespace std;

long long x, y;
long long extended_euclid(long long a, long long b) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extended_euclid(b, a % b);
  long long xx = y, yy = x - (a/b)*y;
  x = xx; y = yy;
  return d;
}

long long n;
long long a, b, p, q;


int main() {
  cin >> n;
  while(n > 0) {
    cin >> p >> a >> q >> b;
    long long d = extended_euclid(a, b);
    if(n % d) {
      puts("failed");
      cin >> n;
      continue;
    }
    a/=d; b/=d; n/=d;
    x *= n; y *= n;
    long long k = x <= 0 ? (-x + b)/b : (-x)/b;
    x += b*k;
    y -= a*k;
    if(x <= 0)
      x += b, y -= a;
    k = y <= 0 ? (-y + a)/a : -y/a;
    long long xx = x - b*k, yy = y + a*k;
    if(yy <= 0)
      yy += a, xx -= b;
    // cout << x << " " << y << " " << xx << " " << yy << endl;
    if((xx >= 0 && yy >= 0 && xx*p + yy*q < x*p + y*q) || (y < 0) || (x < 0))
      x = xx, y = yy;
    if(x < 0 || y < 0)
      puts("failed");
    else
      cout << x << " " << y << endl;
    cin >> n; 
  }
  
  return 0;
}