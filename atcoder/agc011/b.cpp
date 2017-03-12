#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
int a[N], n;

bool can(int x) {
  long long now = a[x];
  for (int i = 0; i < n; i++) {
    if (i == x) continue;
    if (now * 2 < a[i])
      return 0;
    now += a[i];
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r)/2;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", n-l);
  return 0;
}