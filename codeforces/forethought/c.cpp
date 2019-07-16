#include <bits/stdc++.h>

using namespace std;

int ask(int v, int l, int r) {
  printf("1 %d %d", r-l + 1, v);
  for (int x = l; x <= r; ++x) {
    printf(" %d", x);
  }
  printf("\n");
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1) {
    exit(0);
  }
  return res;
}

int ask2(int v, vector<int> nodes) {
  printf("1 %d %d", (int)nodes.size(), v);
  for (int x : nodes) {
    printf(" %d", x);
  }
  printf("\n");
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1) {
    exit(0);
  }
  return res;
}

void answer(int d) {
  printf("-1 %d\n", d);
  fflush(stdout);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int big = ask(1, 2, n);
    int lo = 2, hi = n;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      int res = ask(1, lo, mid);
      if (res == big)
        hi = mid;
      else
        lo = mid + 1;
    }
    vector<int> nodes;
    for (int i = 1; i <= n; ++i) {
      if (i == lo) continue;
      nodes.push_back(i);
    }
    int ans = ask2(lo, nodes);
    answer(ans);
  }
  return 0;
}
