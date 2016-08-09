#include <bits/stdc++.h>

using namespace std;

const int N = 103;

int a[N], n;

int main() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    sum += a[i];
  }
  sum /= (n/2);
  for(int i = 0; i<n; i++) if(a[i]) {
    for(int j = i+1; j<n; j++)
      if(a[i] + a[j] == sum) {
        printf("%d %d\n", i+1, j+1);
        a[i] = a[j] = 0;
      }
  }

  return 0;
}