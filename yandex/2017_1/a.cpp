#include <bits/stdc++.h>

using namespace std;

const int N = 2024;

int n, a, b, x[N], ans[N], d[N];

int read(int l, int r, int w) {
  if (r < l) return l;
  int len = r-l + 1, up = (len + 1) / 2;
  for (int i = 0; i < up; ++i) {
    ans[l+i] = w;
  }
  return l + up;
}

int main() {
  scanf("%d %d %d", &n, &a, &b);
  memset(d, -1, sizeof d);
  for (int i = 0; i < n; i++) {
    scanf("%d", x+i);
    d[x[i]] = i;
    ans[i] = x[i] + b;
  }
  int last = 0, cur = -1;
  int w = 0;
  while (last < n) {
    if (d[w] != -1)
      cur = d[w];
    if ((w-x[last] >= b) || (cur-last+1) >= a)
      last = read(last, cur, w);
    w++;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}