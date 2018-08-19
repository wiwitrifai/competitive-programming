#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 60;
  printf("%d\n", t);
  srand(time(0));
  while (t--) {
    int m = 50, k = 50;
    int x = rand() & 1;
    printf("%d %d\n", m, k);
    for (int i = 0; i < m; ++i) {
      int a = rand() & 1;
      if (a) a = 50;
      else a = -50;
      printf("%d%c", a, i == m-1 ? '\n' : ' ');
    }
  }
  return 0;
}