#include <bits/stdc++.h>

using namespace std;

int main() {
  printf("%d\n", 1000);
  for (int n = 1; n <= 5; n++) {
    for (int s = 0; s <= 10; s++) {
      for (int k = 0; k <= 20; k++) {
        printf("%d %d %d\n", n, s, k);
      }
    }
  }
  return 0;
}