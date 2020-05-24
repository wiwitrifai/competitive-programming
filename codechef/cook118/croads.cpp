#include <bits/stdc++.h>

using namespace std;

long long solve(int n) {
  if ((n & (n-1)) == 0) {
    return -1;
  }
  long long pw = 1;
  long long ret = 0;
  while (pw <= n) {
    ret += ((n / pw) - (n / (pw * 2))) * pw;
    pw <<= 1;
  }
  return ret-1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", solve(n));
  }
  return 0;
}
