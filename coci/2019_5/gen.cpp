#include <bits/stdc++.h>

using namespace std;

char crand() {
  int x = rand() % 40;
  if (x >= 26)
    return '?';
  return 'a' + x;
}

int main(int argc, char * argv[]) {
  srand(0);
  int n = 5e4, m = 6;
  printf("%d %d\n", n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      printf("%c", crand());
    printf("\n");
  }
  return 0;
}