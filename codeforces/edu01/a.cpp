#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long m = n;
    long long sum = m * (m+1)/2;
    long long sub = 0, now = 1;
    while (now <= m) {
      now <<= 1;
      sub += now;
    }
    printf("%I64d\n", sum - sub);
  }
  return 0;
}