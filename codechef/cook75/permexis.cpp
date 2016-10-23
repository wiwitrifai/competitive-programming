#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
    }
    sort(a, a+n);
    bool ok = true;
    for (int i = 1; i < n; i++) {
      ok &= abs(a[i] - a[i-1]) <= 1;
    }
    puts(ok ? "YES" : "NO");
  }

  return 0;
}