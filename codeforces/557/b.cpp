#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int id[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    if (a > b)
      swap(a, b);
    g[a].push_back((b + n - a) % n);
    g[b].push_back((a + n - b) % n);
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
  }
  for (int k = 1; k < n; ++k) {
    if (n % k) continue;
    bool same = 1;
    for (int i = 0, j = k; i < n && same; ++i, ++j) {
      while (j >= n) j -= n;
      same &= g[i] == g[j];
    }
    if (same) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
