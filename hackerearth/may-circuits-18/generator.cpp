#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int n, q;
  scanf("%d", &n);
  srand(time(0));
  q = n;
  printf("%d %d\n", n, q);
  for (int i = 0; i < n; ++i) {
    a[i] = rand();
    printf("%lld%c", a[i], i == n-1 ? '\n' : ' ');
  }
  long long mi = a[0];
  for (int i = 0; i < n; ++i)
    mi = min(mi, a[i]);
  for (int i = 0; i < q; ++i) {
    int t = rand() & 1;
    ++t;
    printf("%d ", t);
    if (t == 1) {
      long long x = rand();
      printf("%lld\n", x);
    }
    else {
      long long l = min(rand(), (int)mi+1), r = rand();
      int x = rand() % n;
      ++x;
      if (l > r) swap(l, r);
      printf("%lld %lld %d\n", l, r, x);
    }
  }

  return 0;
}