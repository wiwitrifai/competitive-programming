#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    bool neg = false, pos = false;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
      if (a[i] != b[i]) {
        if (a[i] > b[i]) {
          ok &= neg;
        }
        else {
          ok &= pos;
        }
      }
      if (a[i] > 0)
        pos = true;
      else if (a[i] < 0)
        neg = true;
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
