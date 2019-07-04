#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], id[N];

int ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> events;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
    events.emplace_back(a[i], ~i);
    events.emplace_back(b[i], i);
  }
  sort(events.begin(), events.end());
  int cnt = 0, tot = 0;
  for (auto it : events) {
    int v = it.second;
    if (v < 0) {
      v = ~v;
      ++tot;
      ans[v] = cnt - tot;
      ++cnt;
    }
    else {
      ans[v] += tot;
      --cnt;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
