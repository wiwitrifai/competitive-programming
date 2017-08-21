#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  long long x = -1, y = -1;
  for (int i = n-2; i >= 0; i--) {
    if (a[i] == a[i+1]) {
      if (x == -1) {
        x = a[i];
        a[i] = -1;
      }
      else {
        printf("%lld\n", x * a[i]);
        return 0;
      }
    }
  }
  printf("%lld\n", 0);
  return 0;
}