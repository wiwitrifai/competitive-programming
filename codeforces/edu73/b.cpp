#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf((i + j) & 1 ? "W" : "B");
    }
    printf("\n");
  }
  return 0;
}
