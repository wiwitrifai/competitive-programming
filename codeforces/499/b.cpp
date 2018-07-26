#include <bits/stdc++.h>

using namespace std;

int m, n;
int cnt = 0;
int ask(int x) {
  ++cnt;
  assert(cnt <= 60);
  printf("%d\n", x);
  fflush(stdout);
  int r;
  scanf("%d", &r);
  if (r == 0) {
    exit(0);
  }
  assert(r == -1 ||r == 1);
  return r;
}

const int N = 1e5 + 5;
int p[N];

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; ++i) {
    p[i] = ask(1);
  }
  int l = 1, r = m;
  int i = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    int res = ask(mid);
    if (p[i] < 0)
      res = -res;
    if (res > 0)
      l = mid + 1;
    else
      r = mid - 1;
    i = (i + 1) % n;
  }
  ask(r);
  assert(false);
  return 0;
}