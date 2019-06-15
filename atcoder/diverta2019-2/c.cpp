#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> vx;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    vx.push_back(x);
  }
  sort(vx.begin(), vx.end());
  int kecil = vx[0], besar = vx.back();
  vector<pair<int, int>> ans;
  for (int i = 1; i + 1 < n; ++i) {
    int x = vx[i];
    if (x >= 0)
      ans.emplace_back(kecil, x), kecil -= x;
    else
      ans.emplace_back(besar, x), besar -= x;
  }
  ans.emplace_back(besar, kecil);
  printf("%d\n", besar - kecil);
  for (auto it : ans)
    printf("%d %d\n", it.first, it.second);
  return 0;
}
