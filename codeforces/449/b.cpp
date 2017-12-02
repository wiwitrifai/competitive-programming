#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int naik[N], turun[N], a, b;

int main() {
  int n, m, c;
  scanf("%d %d %d", &n, &m, &c);
  a = 0;
  b = 0;
  while ((a + b) < n) {
    int x;
    scanf("%d", &x);
    if (x <= c/2) {
      int id = upper_bound(naik, naik+a, x) - naik;
      printf("%d\n", id+1);
      fflush(stdout);
      naik[id] = x;
      a += id == a;
    }
    else {
      x = -x;
      int id = upper_bound(turun, turun+b, x) - turun;
      printf("%d\n", n-id);
      fflush(stdout);
      turun[id] = x;
      b += id == b;
    }
  }
  return 0;
}