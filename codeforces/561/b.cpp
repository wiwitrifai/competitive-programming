#include <bits/stdc++.h>

using namespace std;

char vowels[] = "aiueo";

int main() {
  int k;
  scanf("%d", &k);
  for (int i = 5; i < k; ++i) {
    if (k % i) continue;
    int x = k / i;
    if (x < 5) continue;
    for (int r = 0; r < i; ++r) {
      for (int c = 0; c < x; ++c) {
        printf("%c", vowels[(r+c) % 5]);
      }
    }
    printf("\n");
    return 0;
  }
  puts("-1");
  return 0;
}
