#include <bits/stdc++.h>

using namespace std;

int x[3], mx[3], ax[3];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 3; i++)
      scanf("%d", x+i);
    int n;
    scanf("%d", &n);
    if (n == 0) {
      int ans  = 0;
      for (int i = 0; i < 3; i++)
        ans ^= (x[i]-1);
      puts(ans ? "Alice" : "Bob");
      continue;
    }
    for (int i= 0; i < 3; i++) {
      scanf("%d", mx+i);
      ax[i] = mx[i];
    }
    for (int i = 1; i < n; i++) {
      int v[3];
      for (int j = 0; j < 3; j++) {
        scanf("%d", v+j);
        mx[j] = min(mx[j], v[j]);
        ax[j] = max(ax[j], v[j]);
      }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
      ans ^= (mx[i]-1) ^ (x[i] - ax[i]);
    puts(ans ? "Alice" : "Bob");
  }

  return 0;
}