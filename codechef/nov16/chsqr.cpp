#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int k;
    scanf("%d", &k);
    int first = k/2 + 1;
    for (int i = 0; i < k; i++) {
      for (int j = 0, z = first; j < k; j++, z++) {
        if (z > k)
          z = 1;
        printf("%d ", z);
      }
      printf("\n");
      first--;
      if (first < 1)
        first = k;
    }
  }
  return 0;
}