#include <bits/stdc++.h>

using namespace std;

int ask(int start, int d) {
  printf("?");
  for (int i = 0; i < 100; ++i, start += d)
    printf(" %d", start);
  printf("\n");
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}

int main() {
  int mask = (1 << 7) - 1;
  int ans = (ask(0, 1) & (mask << 7)) | (ask(1 << 7, 1 << 7) & mask);
  printf("! %d\n", ans);
  fflush(stdout);
  return 0;
}
