#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  assert(n == 1);
  int now = 0;
  for (int i = 0; i < k; ++i) {
    int a;
    scanf("%d", &a);
    printf("0 1 %d %d\n", now, now + a);
    now += a;
  }
  return 0;
}
