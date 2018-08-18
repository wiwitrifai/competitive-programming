#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  long long all = 1LL * n * n;
  long long mid = (all + 1) / 2;
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if ((x + y) & 1) {
      int ganjil = n/2, genap = n - ganjil;
      int k = ((x-1) / 2) * 2;
      long long cnt = mid + 1LL * (ganjil + genap) * (k / 2);
      if (k + 1 < x)
        cnt += ganjil;
      cnt += (y + 1) / 2;
      printf("%lld\n", cnt);
    }
    else {
      int ganjil = (n + 1)/2, genap = n - ganjil;
      int k = ((x-1) / 2) * 2;
      long long cnt = 1LL * (ganjil + genap) * (k / 2);
      if (k + 1 < x)
        cnt += ganjil;
      cnt += (y + 1) / 2;
      printf("%lld\n", cnt);
    }
  }
  return 0;
}