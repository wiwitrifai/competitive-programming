#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]), --a[i];
  bool ok0 = 1;
  int lef = n+1, rig = -1;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    ok0 &= a[i] == i;
    if (a[i] != i) {
      lef = min(lef, i);
      rig = max(rig, i);
      ++cnt;
    }
  }
  if (ok0)
    printf("0\n");
  else if (rig - lef+1 == cnt)
    printf("1\n");
  else
    printf("2\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
