#include <bits/stdc++.h>

using namespace std;

int main() {
  int d, t, a, b;
  if ((a - b) * t >= d) {
    int v = a - b;
    printf("%d\n", (d + v - 1) / v);
  }
  else {
    d -= (a - b) * t;
    printf("%d\n", (d + a - 1) / a);
  }
  return 0;
}