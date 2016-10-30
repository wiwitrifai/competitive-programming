#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > food[N];
int dist(int a, int b) {
  int ret = 0;
  while (a != b) {
    if (a > b)
      a >>= 1;
    else
      b >>= 1;
    ret++;
  }
  return ret;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    int c;
    scanf("%d", &c);
    while (c--) {
      int a;
      scanf("%d", &a);
      food[i].push_back(a);
    }
  }
  int now = 1, ans = 0;
  while (q--) {
    int f, p;
    scanf("%d %d", &f, &p);
    int cur = N;
    for (int ff : food[f]) {
      cur = min(cur, dist(now, ff) + dist(ff, p));
    }
    ans += cur;
    now = p;
  }
  printf("%d\n", ans);

  return 0;
}