#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

int main() {
  for (int i = 2; i < N; i++) if (a[i] == 0) {
    for (int j = i + i; j < N; j += i)
      a[j] = 1;
  }
  int n;
  scanf("%d", &n);
  puts((n >= 3) ? "2" : "1");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i+2] + 1);
  printf("\n"); 
  return 0;
}