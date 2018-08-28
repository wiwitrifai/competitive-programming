#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int len = 0;
  int sum = 5;
  len = 0;
  while (sum < n) {
    sum += 4;
    printf("4");
    ++len;
  }
  printf("5\n");
  for (int i = 0; i <= len; ++i)
    printf("5");
  printf("\n");
  return 0;
}