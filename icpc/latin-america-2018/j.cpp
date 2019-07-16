#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N];
bool ok[N];
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int n;
  scanf("%s", s);
  n = strlen(s);
  vector<int> divs;
  for (int i = 1; i < n; ++i) {
    if (n % i) continue;
    divs.push_back(i);
  }
  for (int d : divs) {
    bool res = 0;
    for (int r = 0; r < d; ++r) {
      res = 1;
      for (int i = r; i < n; i += d)
        if (s[i] != 'R') {
          res = 0;
          break;
        }
      if (res)
        break;
    }
    ok[d] = res;
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int d = gcd(i, n);
    ans += ok[d];
  }
  printf("%d\n", ans);
  return 0;
}