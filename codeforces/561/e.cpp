#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4, M = 55;

bitset<N> big[M];
int sz[M];

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; ++i) {
    int s;
    big[i].reset();
    scanf("%d", &s);
    sz[i] = s;
    while (s--) {
      int x;
      scanf("%d", &x);
      --x;
      big[i][x] = 1;
    }
    assert((int)big[i].count() == sz[i]);
  }
  bool ok = 1;
  for (int i = 0; i < m && ok; ++i) {
    for (int j = 0; j < m && ok; ++j) {
      if (i == j) continue;
      if ((int)(big[j].flip() & big[i]).count() == sz[i]) {
        ok = 0;
      }
      big[j].flip();
    }
  }
  puts(ok ? "possible" : "impossible");
  return 0;
}
