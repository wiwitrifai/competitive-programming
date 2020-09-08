#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  vector<int> b(n, -1);
  int last = 0;
  for (int i = 0; i < n; ++i) {
    int sel = -1;
    for (int j = 0; j < n; ++j) {
      if (a[j] < 0) continue;
      if (sel == -1 || gcd(last, a[j]) > gcd(last, a[sel]))
        sel = j;
    }
    last = gcd(last, a[sel]);
    b[i] = a[sel];
    a[sel] = -1;
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", b[i], i+1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
