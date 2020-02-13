#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    int mini = 1e9 + 7, maxi = -1;
    for (int i = 0; i + 1 < n; ++i) {
      if (a[i] == -1 && a[i+1] == -1) continue;
      if (a[i] != -1 && a[i+1] != -1) continue;
      int now = a[i] + a[i+1] + 1;
      mini = min(mini, now);
      maxi = max(maxi, now);
    }

    if (mini > maxi)
      puts("0 0");
    else {
      int k = (maxi + mini) / 2;
      for (int i = 0; i < n; ++i) {
        if (a[i] == -1)
          a[i] = k;
      }
      int m = 0;
      for (int i = 0; i + 1 < n; ++i) {
        m = max(m, abs(a[i+1] - a[i]));
      }
      printf("%d %d\n", m, k);
    }
  }
  return 0;
}
