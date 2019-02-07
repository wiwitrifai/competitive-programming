#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
  }
  bool ok = a[0] == b[0] && a[n-1] == b[n-1];
  for (int i = 0; i+1 < n; ++i) {
    a[i] = a[i+1] - a[i];
    b[i] = b[i+1] - b[i];
  }
  sort(a, a+n-1);
  sort(b, b+n-1);
  for (int i = 0; i < n-1; ++i)
    ok &= a[i] == b[i];
  puts(ok ? "Yes" : "No");
  return 0;
}