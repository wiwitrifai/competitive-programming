#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 100;
  printf("%d\n", t);
  while (t--) {
    int r = 100, c = 100, w = 100;
    printf("%d %d %d\n", r, c, w);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j)
        printf("a");
      printf("\n");
    }
    for (int i = 0; i < w; ++i) {
      for (int j = 0; j <= i; ++j)
        printf("a");
      printf("\n");
    }
  }
  return 0;
}