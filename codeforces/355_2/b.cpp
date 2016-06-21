#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, a[N];
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int now = 1;
  for(int i = 0; i<n; i++) {
    if(now <= a[i])
      now++;
  }
  printf("%d\n", now);
  return 0;
}