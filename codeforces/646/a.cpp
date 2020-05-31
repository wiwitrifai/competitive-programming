#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      cnt[x & 1]++;
    }
    if (k == n) {
      int tot = cnt[1];
      puts(tot & 1 ? "Yes" : "No");
      continue;
    }
    if (k == 1) {
      puts(cnt[1] > 0 ? "Yes" : "No");
      continue;
    }
    if (cnt[1] == 0) {
      puts("NO");
      continue;
    }
    if (cnt[0] == 0) {
      puts(k & 1 ? "Yes" : "No");
      continue;
    }
    puts("Yes");
  }

  return 0;
}
