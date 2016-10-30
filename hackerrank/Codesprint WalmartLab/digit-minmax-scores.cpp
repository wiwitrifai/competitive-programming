#include <bits/stdc++.h>

using namespace std;

long long solve(long long n) {
  long long ret = 0;
  for(int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if ((i-j) * (j-k) < 0) {
          long long now = i * 100 + j * 10 + k;
          long long left = n / 1000, right = 1;
          while (left) {
            ret += (left - 1) * right;
            if (i)
              ret += right;
            ret += max(0LL, min(right, n - (left * 1000LL + now) * right + 1));
            left /= 10;
            right *= 10;
          }
          if (i) {
            ret += max(0LL, min(right, n - now * right + 1));
          }
        }
      }
    }
  }
  return ret;
}
int main() {
  long long a, b;
  cin >> a >> b;
  // cerr << solve(b) << " " << solve(a) << endl;
  cout << solve(b) - solve(a-1) << endl;
  return 0;
}