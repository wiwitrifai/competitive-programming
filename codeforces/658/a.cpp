#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N], t[N];

void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s %s", s, t);
  for (int i = 0; i < n; ++i) {
    s[i] -= '0';
    t[i] -= '0';
  }
  vector<int> ans;
  bool invs = false;
  int lef = 0, rig = n-1;
  auto get_lef = [&]() {
    return (int)(invs ? !s[lef] : s[lef]);
  };
  auto get_rig = [&]() {
    return (int)(invs ? !s[rig] : s[rig]);
  };
  auto maju = [&]() {
    if (rig > lef)
      --rig;
    else
      ++rig;
  };
  for (int i = 0; i < n; ++i) {
    if (get_rig() == t[n-i-1]) {
      maju();
      continue;
    }
    if (get_lef() == t[n-i-1])
      ans.push_back(1);
    ans.push_back(n-i);
    invs = !invs;
    swap(lef, rig);
    maju();
  }
  printf("%d", (int)ans.size());
  for (int x : ans) {
    printf(" %d", x);
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
