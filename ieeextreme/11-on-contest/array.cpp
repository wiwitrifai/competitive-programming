#include <bits/stdc++.h>

using namespace std;


const int N = 1e6 + 5, D = 6;

int a[D], d, dim[D], b[D];
long long val[N];

void id(int now, int * x) {
  for (int i = d-1; i >= 0; i--) {
    if (i == 0)
      x[i] = now;
    else
      x[i] = now % dim[i-1], now /= dim[i-1];
  }
}
long long get(int x = 0, int y = 0) {
  if (x == d) {
    return val[y];
  }
  if (x > 0)
    y *= dim[x-1];
  long long ret = 0;
  if (b[x] >= 0)
    ret += get(x+1, y + b[x]);
  if (a[x] >= 0)
    ret -= get(x+1, y + a[x]); 
  return ret;
}

int main() {
  scanf("%d", &d);
  int n = 1;
  for (int i = 0; i < d; i++)
    scanf("%d", dim+i), n *= dim[i];
  for (int i = 0; i < n; i++) {
    int now;
    scanf("%d", &now);
    id(i, b);
    for (int j = 0; j < d; j++)
      a[j] = b[j] - 1;
    val[i] = now - get();
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    for (int i = 0; i < d; i++)
      scanf("%d", a+i), a[i] -= 2;
    for (int i = 0; i < d; i++)
      scanf("%d", b+i), b[i] -= 1;
    printf("%lld\n", get());
  }
  return 0;
}