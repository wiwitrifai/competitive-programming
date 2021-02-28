#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int d = 0;
  for (int i = 0; i + 1 < n; ++i)
    d = gcd(d, abs(a[i+1] - a[i]));
  vector<int> candidates;
  for (int i = 1; i * i <= d; ++i) {
    if (d % i) continue;
    candidates.push_back(i);
    int x = d / i;
    if (x != i)
      candidates.push_back(x);
  }
  sort(candidates.rbegin(), candidates.rend());
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l = a[0] + l - 1;
    r = a[0] + r;
    int ans = 1;
    if (d == 0)
      ans = r;
    else {
      for (int x : candidates) {
        if (r/x > l/x) {
          ans = x;
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
