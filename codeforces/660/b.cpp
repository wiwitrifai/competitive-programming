#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  int d = (n + 3) / 4;
  int cnt = n - d;
  for (int i = 0; i < cnt; ++i) {
    printf("9");
  }
  int sisa = d * 4 - n;
  int last = 8;
  for (int i = 0; i < sisa; ++i) {
    if ((last | (1 << (3 - i))) <= 9) {
      last |= 1 << (3-i);
    }
  }
  printf("%d", last);
  for (int i = 0; i < d-1; ++i)
    printf("8");
  printf("\n");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
