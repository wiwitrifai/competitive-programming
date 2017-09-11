#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      a[i] = i;
    }
    for (int i = 1; i <= n; i += 2) {
      if (i == n)
        swap(a[i-1], a[i]);
      else
        swap(a[i], a[i+1]);
    }
    for (int i = 1; i <= n; i++)
      printf("%d%c", a[i], i == n ? '\n' : ' ');
  }
  return 0;
}