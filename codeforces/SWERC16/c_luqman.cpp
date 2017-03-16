#include <bits/stdc++.h>

using namespace std;

int main() {
  int d, R, T;
  scanf("%d %d %d", &d, &R, &T);
  for (int t = d; t <= 4000; t++) {
    long long cr = 0, ct = 0;
    for (int i = 4; i <= t; i++) cr += i;
    for (int i = 3; i <= t - d; i++) ct += i;
    if (R - cr == ct - T) {
      cout << R - cr << endl;
      return 0;
    }
  }
  return 0;
}