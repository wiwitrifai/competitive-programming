#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  n = m = 5e4;
  srand(time(0));
  printf("%d %d\n", n, m);
  for (int i = 0; i < n; i++) {
    printf("%d ", rand() & 1);
  }
  for (int i = 1; i < n; i++) {
    printf("%d %d\n", i+1, (rand() % i) + 1); 
  }
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", (rand() & 1) + 1, (rand() % n) + 1);
  }
  return 0;
}