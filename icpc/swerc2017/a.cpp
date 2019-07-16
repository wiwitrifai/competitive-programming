#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int a[N], b[N];

int main() {
  map<int, int > mp;
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < m; ++i)
    scanf("%d", b+i);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[j] < a[i]) continue;
      ++mp[(b[j] - a[i])];
    }
  }
  int ans = 0, cnt = -1;
  for (auto it : mp) {
    if (it.second > cnt) {
      ans = it.first;
      cnt = it.second;
    }
    else if (it.second == cnt)
      ans = min(it.first, ans);
    //~ cerr << it.first << " " << it.second << endl;
  }
  printf("%d\n", ans);
  return 0;
}
