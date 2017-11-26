#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int n, k;
long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  scanf("%d %d %s", &n, &k, s);
  int kiri = 0, kanan = 0;
  long long tot = 0, ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    tot += kanan + kiri;
    if (s[i] == ')') {
      ans += kiri;
      kanan++;
    }
    else
      kiri++;
    if (i-k >= 0) {
      if (s[i-k] == ')')
        kanan--;
      else
        kiri--;
    }
  }
  if (tot == 0) {
    puts("0/1");
  }
  else {
    long long g = gcd(tot, ans);
    tot /= g;
    ans /= g;
    printf("%lld/%lld\n", ans, tot);
  }
  return 0;
}