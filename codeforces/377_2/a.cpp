#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, r; 
  cin >> k >> r;
  for (int i = 1; i <= 10; i++) {
    int rr = (i * k) % 10;
    if (rr == r || rr == 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");

  return 0;
}