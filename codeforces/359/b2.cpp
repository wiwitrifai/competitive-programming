#include <bits/stdc++.h>

using namespace std;

int a[105], n;
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  for(int i = 0; i<n; i++) {
    for(int j = n-1; j>i; j--)
      if(a[j] < a[j-1]) {
        printf("%d %d\n", j, j+1);
        swap(a[j], a[j-1]);
      }
  }
  return 0;
}