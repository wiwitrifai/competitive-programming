#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int h[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", h+i);
    bool ok = 1;
    for (int i = 0; i + 1 < n; ++i) {
      int low = max(h[i+1]-k, 0);
      if (low <= h[i]) {
        m += h[i] - low;
      }
      else if (h[i] < low) {
        int rem = low - h[i];
        if (m < rem) {
          ok = 0;
          break;
        }
        m -= rem;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
