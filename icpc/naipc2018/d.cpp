#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], used[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", a+i);
    used[a[i]] = 1;
  }
  int j = 1;
  for (int i = 0; i < m; ++i) {
    while (j < a[i]) {
      if (!used[j])
        printf("%d\n", j);
      ++j;
    }
    printf("%d\n", a[i]);
  }
  while (j <= n) {
    if (!used[j])
      printf("%d\n", j);
    ++j;
  }

  return 0;
}
