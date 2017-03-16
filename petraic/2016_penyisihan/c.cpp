#include <bits/stdc++.h>

using namespace std;

void print(int n, int k) {
  for (int i = 1; i <= k; i++)
    printf("%d", i);
  int a = n - k;
  a = a * 2 - 1;
  for (int j = 0; j < a; j++)
    printf(" ");
  for (int j = min(k, n-1); j > 0; j--) 
    printf("%d", j);
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    print(n, i);
  for (int i = n-1; i > 0; i--)
    print(n, i);
  return 0;
}