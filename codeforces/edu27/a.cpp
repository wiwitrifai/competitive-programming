#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", a+i);
  }
  sort(a, a+2 *n);
  puts(a[n-1] < a[n] ? "YES" : "NO");
  return 0;
}