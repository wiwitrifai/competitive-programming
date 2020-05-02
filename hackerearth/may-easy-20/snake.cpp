#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int>> apples;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    apples.emplace_back(x, y, i);
  }
  sort(apples.begin(), apples.end());
  bool maju = 1;
  for (int i = 0; i < n; ) {
    int j = i+1;
    while (j < (int)apples.size() && get<0>(apples[j]) == get<0>(apples[i])) ++j;
    if (!maju)
      reverse(apples.begin()+i, apples.begin()+j);
    maju = !maju;
    i = j;
  }
  for (int i = 0; i < n; ++i) {
    int x, y, id;
    tie(y, x, id) = apples[i];
    ans[id] = i;
  }
  for (int x : ans)
    printf("%d\n", x);
  return 0;
}
