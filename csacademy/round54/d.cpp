#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > ed;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  k = n-1-k;
  if (n == 2) {
    if (k == 1)
      puts("-1");
    else {
      puts("1");
      puts("1 2 1");
    }
    return 0;
  }
  if (n == 3 && k == 2) {
    puts("-1");
    return 0;
  }
  if (n == 3) {
    printf("%d\n", n-1 + k);
    printf("1 2 1\n");
    printf("2 3 2\n");
    if (k == 1)
      printf("3 1 3\n");
    return 0;
  }
  printf("%d\n", n-1 + k);
  int d = 1;
  for (int i = 2; i < n; i++) {
    printf("%d %d %d\n", i, 1, d++);
  }
  if (n > 3)
    printf("%d %d %d\n", n, 3, d++);
  for (int i = 3; i <= n && k > 0; i++) {
    printf("%d %d %d\n", 2, i, d++);
    k--;
  }
  if (k)
    printf("%d %d %d\n", 1, n, d++);
  return 0;
}