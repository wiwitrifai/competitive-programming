#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  n = unique(a, a+n)-a;
  scanf("%d", &m);
  while (m--) {
    int x;
    scanf("%d", &x);
    int id = lower_bound(a, a+n, x)-a;
    if (id == n)
      puts("Dr. Samer cannot take any offer :(.");
    else
      printf("%d\n", a[id]);
  }
  return 0;
}