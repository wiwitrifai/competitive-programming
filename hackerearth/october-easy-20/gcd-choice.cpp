#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  vector<int> lef(n+1, 0), rig(n+1, 0);
  for (int i = 0; i < n; ++i)
    lef[i+1] = gcd(lef[i], a[i]);
  for (int i = n-1; i >= 0; --i) {
    rig[i] = gcd(rig[i+1], a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, gcd(lef[i], rig[i+1]));
  }
  printf("%d\n", ans);
  return 0;
}
