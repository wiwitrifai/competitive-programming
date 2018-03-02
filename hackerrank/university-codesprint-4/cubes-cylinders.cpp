#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

pair<int, int> package[N], container[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    package[i].first = x;
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    package[i].second = x;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    container[i].first = x;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    container[i].second = x;
  }
  int ans = 0;
  sort(package, package+n);
  sort(container, container+m);
  for (int i = 0, j = 0; i < n; ++i) {
    int s = package[i].first, k = package[i].second;
    while (k > 0 && j < m) {
      while (j < m && container[j].first * container[j].first * 2 <= s * s || container[j].second <= 0) ++j;
      if (j < m) {
        int used = min(k, container[j].second);
        ans += used;
        k -= used;
        container[j].second -= used;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}