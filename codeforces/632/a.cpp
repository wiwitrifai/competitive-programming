#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    if ((n & 1) && (m & 1)) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          printf("%c", ((i+j) & 1) ? 'W' : 'B');
        }
        printf("\n");
      }
    }
    else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          printf("%c", ((i == 0 && j == 0) || ((i+j) & 1)) ? 'B' : 'W');
        }
        printf("\n");
      }
    }
  }
  return 0;
}
