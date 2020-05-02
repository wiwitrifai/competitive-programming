#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  long long ans = 1LL * a[1] * (a[1]-1) * (a[1]-2) / 2 + 1LL * a[1] * a[2] * (a[2] - 1)/2 + 1LL * a[1] * a[2] * a[3];
  for (int i = 2; i < N; i++) if (a[i]) {
    ans += 1LL * ((i+2)/i) * a[i] * a[1] * (a[1]-1)/2; 
  }
  printf("%lld\n", ans);
  return 0;
}