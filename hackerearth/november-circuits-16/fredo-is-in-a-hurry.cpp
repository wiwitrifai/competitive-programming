#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      long long naik = 1LL * mid * (mid + 1) / 2;
      int turun = n-mid;
      if (naik <= turun)
        l = mid;
      else
        r = mid-1; 
    }
    printf("%d\n", max(2*(n-l), 1));
  }

  return 0;
}