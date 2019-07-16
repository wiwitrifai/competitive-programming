#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int s[N], t[N], id[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", s+i), id[i] = i, sum += s[i];
  sort(id, id+n, [](int l, int r) { return s[l] < s[r]; });
  for (int i = 0; i < n; ++i)
    scanf("%d", t+i), sum -= t[i];
  sort(t, t+n);
  if (sum != 0) {
    puts("NO");
    return 0;
  }
  vector<pair<int, int>> rest;
  vector<tuple<int, int, int>> ans;
  for (int i = 0; i < n; ++i) {
    int d = t[i] - s[id[i]];
    if (d > 0) {
      rest.emplace_back(d, i);
      continue;
    }
    while (d < 0) {
      if (rest.empty()) {
        puts("NO");
        return 0;
      }
      int x = min(-d, rest.back().first);
      ans.emplace_back(id[rest.back().second]+1, id[i]+1, x);
      if (rest.back().first == x)
        rest.pop_back();
      else
        rest.back().first -= x;
      d += x;
    }
  }
  if (!rest.empty()) {
    puts("NO");
    return 0;
  }
  printf("YES\n%d\n", (int)ans.size());
  for (auto it : ans) {
    int i, j, d;
    tie(i, j, d) = it;
    printf("%d %d %d\n", i, j, d);
  }

  return 0;
}
