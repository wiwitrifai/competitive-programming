#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n-1);
  for (int i = 0; i < n-2; ++i)
    printf("1 ");
  printf("2\n");
  return 0;
}