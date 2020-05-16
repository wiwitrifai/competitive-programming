#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  if (2 * n <= s) {
    puts("YES");
    for (int i = 0; i < n-1; ++i)
      printf("1 ");
    printf("%d\n", s-(n-1));
    printf("%d\n", n);
  }
  else {
    puts("NO");
  }
  return 0;
}
