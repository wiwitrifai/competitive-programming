#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int t = (n+1)/2;
  int mid = t;
  for(int i = 0; i<mid; i++) {
    printf("%d ", a[i]);
    if(t < n)
      printf("%d ", a[t++]);
  }
  return 0;
}