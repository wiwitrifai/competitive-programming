#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  bool same = 1;
  long long sum = 0;
  int mi = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
    sum += a[i];
    if (a[i] > b[i]) {
      mi = min(mi, b[i]);
      same = 0;
    }
  }
  if (same)
    puts("0");
  else
    printf("%lld\n", sum - mi);

  return 0;
}