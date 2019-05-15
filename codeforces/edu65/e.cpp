#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int lef[N], rig[N];
vector<int> pos[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    pos[a].push_back(i);
  }
  memset(lef, -1, sizeof lef);
  memset(rig, -1, sizeof rig);
  lef[0] = 0;
  for (int i = 1; i <= x; ++i) {
    lef[i] = lef[i-1];
    for (int p : pos[i]) {
      if (p <= lef[i]) {
        lef[i] = -1;
        break;
      }
      lef[i] = p;
    }
    if (lef[i] == -1)
      break;
  }
  rig[x+1] = n+1;
  for (int i = x; i >= 1; --i) {
    reverse(pos[i].begin(), pos[i].end());
    rig[i] = rig[i+1];
    for (int p : pos[i]) {
      if (p >= rig[i]) {
        rig[i] = -1;
        break;
      }
      rig[i] = p;
    }
    if (rig[i] == -1)
      break;
  }
  long long ans = 0;
  for (int l = 0, r = 1; r <= x+1; ++r) {
    if (rig[r] == -1) continue;
    while (l + 1 < r && lef[l] != -1 && lef[l] < rig[r]) {
      ++l;
    }
    ans += l;
  }
  printf("%lld\n", ans);
  return 0;
}
