#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n;
long long fac[20];


int main() {
  fac[0] = 1;
  for(int i = 1; i<20; i++)
    fac[i] = fac[i-1] * i;
  scanf("%d", &n);
  int last = 0;
  bool sorted = true;
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    if(x < last)
      sorted = false;
    last = x;
    a[x]++;
  }
  if(sorted) {
    puts("0.000000");
    return 0;
  }
  long long ans = fac[n];
  for(int i = 1; i<=100; i++) {
    int now = a[i];
    ans /= fac[now];
  }
  printf("%lld.000000\n", ans);
  return 0;
}