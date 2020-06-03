#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int a[N], n, b[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  int bef = n-1;
  for(int i = 0; i<n; i++) {
    b[i] = a[bef] + a[(i+1) % n];
    bef = i;
  }
  for(int i = 0; i<n; i++)
    printf("%d ", b[i]);
  printf("\n");

  return 0;
}