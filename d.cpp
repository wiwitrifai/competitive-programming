#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-9;

char s[13][10] = {"x^y^z", 
                  "x^z^y", 
                  "(x^y)^z",
                  "(x^z)^y",
                  "y^x^z",
                  "y^z^x",
                  "(y^x)^z",
                  "(y^z)^x",
                  "z^x^y",
                  "z^y^x",
                  "(z^x)^y",
                  "(z^y)^x"
                };
long double a[13], b[13], c[13];

bool cmp(int p, int q) {
  if(c[p] > 1 && c[q] > 1) {
    return (a[p]*log(b[p]) + log(log(c[p]))) < (a[q]*log(b[q]) + log(log(c[q])));
  }
  else if(c[p] > 1)
    return false;
  else if(c[q] > 1)
    return true;
  else {
    long double lef = a[p]*log(b[p]) + log(-log(c[p]));
    long double rig = a[q]*log(b[q]) + log(-log(c[q]));
    return lef > rig;
  }
}

int main() {
  long double x, y, z;
  cin >> x >> y >> z;
  int ans = 0;
  a[0] = z; b[0] = y; c[0] = x;
  a[1] = y; b[1] = z; c[1] = x;
  a[2] = 1; b[2] = y*z; c[2] = x;
  a[3] = 1; b[3] = y*z; c[3] = x;

  a[4] = z; b[4] = x; c[4] = y;
  a[5] = x; b[5] = z; c[5] = y;
  a[6] = 1; b[6] = x*z; c[6] = y;
  a[7] = 1; b[7] = x*z; c[7] = y;

  a[8] = y; b[8] = x; c[8] = z;
  a[9] = x; b[9] = y; c[9] = z;
  a[10] = 1; b[10] = y*x; c[10] = z;
  a[11] = 1; b[11] = y*x; c[11] = z;
  for(int i = 1; i<12; i++) {
    if(cmp(ans, i)) {
      ans = i;
    }
  }
  puts(s[ans]);
  return 0;
}