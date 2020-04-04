#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int ans[N];

int calc(int x) {
  while (x >= 10) {
    x /= 10;
  }
  return x & 1;
}

int main() {
  int now = 1;
  for (int i = 1; i < N; ++i) {
    while (!calc(now)) ++now;
    ans[i] = now++;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    scanf("%d", &k);
    printf("1 %d\n", ans[k]);
  }
  return 0;
}
