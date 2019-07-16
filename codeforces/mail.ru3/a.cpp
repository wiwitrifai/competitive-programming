#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int cnt[N], a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int r;
    scanf("%d", &r);
    for (int j = 0; j < r; ++j)
      scanf("%d", a+j);
    sort(a, a+r);
    r = unique(a, a+r) - a;
    for (int j = 0; j < r; ++j)
      cnt[a[j]]++;
  }
  int ada = 0;
  for (int i = 0; i < N; ++i)
    if (cnt[i] == n) {
      if (ada)
        printf(" ");
      printf("%d", i);
      ++ada;
    }
  printf("\n");
  return 0;
}