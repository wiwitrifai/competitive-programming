#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  int cnt[2];
  cnt[0] = cnt[1] = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]), cnt[a[i]]++;
  int rem[2];
  if (cnt[1] <= cnt[0]) {
    rem[1] = cnt[1];
    rem[0] = 0;
  } else {
    rem[0] = cnt[0];
    rem[1] = 0;
    if (cnt[1] & 1)
      rem[1] = 1;
  }
  printf("%d\n", n - (rem[0] + rem[1]));
  for (int i = 0; i < n; ++i) {
    if (rem[a[i]] > 0) {
      --rem[a[i]];
      continue;
    }
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
