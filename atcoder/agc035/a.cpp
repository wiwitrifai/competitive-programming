#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  if (n % 3) {
    if (a[0] != a[n-1] || a[n-1] != 0) {
      puts("No");
      return 0;
    }
    puts("Yes");
  }
  else {
    int k = n / 3;
    if (a[0] != a[k-1] || a[k] != a[2 * k-1] || a[2*k] != a[n-1] || (a[0] ^ a[k] ^a[2*k]) != 0) {
      puts("No");
      return 0;
    }
    puts("Yes");
  }
  return 0;
}
