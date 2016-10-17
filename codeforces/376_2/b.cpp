#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N];
int  main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1) {
      if (a[i+1] == 0 || i + 1 == n) {
        ok = false;
        break;
      }
      a[i+1]--;
    }
  }
  puts(ok ? "YES" : "NO");
  return 0;
}