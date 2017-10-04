#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int p[N], t[N], id[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i< n; i++) {
    scanf("%d %d", p+i, t+i);
    id[i] = i;
  }
  sort(id, id+n, [](int l, int r) {
    long long val = t[l] * p[r] - t[r] * p[l];
    if (val == 0)
      return l < r;
    return val < 0;
  });
  printf("%d\n", id[0]+1);
  return 0;
}