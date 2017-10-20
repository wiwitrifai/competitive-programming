#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N], d[N];

pair<int, int> find(int x) {
  if (p[x] < 0) {
    return {x, 0};
  }
  auto it = find(p[x]);
  d[x] += it.second;
  p[x] = it.first;
  return {it.first, d[x]};
}

void merge(int u, int v, int w) {
  auto ru = find(u);
  auto rv = find(v);
  if (ru.first == rv.first) {
    return;
  }
  p[ru.first] = rv.first;
  d[ru.first] += w + rv.second - ru.second;
  return;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (n && m) {
    fill(p, p+n+1, -1);
    fill(d, d+n+1, 0);
    while (m--) {
      char c;
      int a, b, w;
      scanf(" %c %d %d", &c, &a, &b);
      if (c == '?') {
        auto ra = find(a);
        auto rb = find(b);
        if (ra.first != rb.first)
          puts("UNKNOWN");
        else
          printf("%d\n", ra.second - rb.second);
      }
      else {
        scanf("%d", &w);
        merge(a, b, w);
      }
    }
    scanf("%d %d", &n, &m);
  }
  return 0;
}