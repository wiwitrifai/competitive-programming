#include <bits/stdc++.h>

using namespace std;

int n;

int cek(int x, int k) {
  if (x < k) return 0;
  int r = x % k;
  while (r) {
    int z = x/k+1;
    int y = (r + z - 1)/z;
    x -= z * y;
    r = x % k;
  }
  return x/k;
}

int main() {
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a, k;
    scanf("%d %d", &a, &k);
    ans ^= cek(a, k);
  }
  puts(ans ? "Takahashi" : "Aoki");
  return 0;
}