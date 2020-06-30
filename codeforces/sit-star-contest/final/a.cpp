#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> ans;
  for (int i = 1; ans.size() < 100; ++i) {
    if (i % 3 && i % 7) continue;
    ans.push_back(i);
  }
  int k;
  scanf("%d", &k);
  printf("%d\n", ans[k-1]);
  return 0;
}
