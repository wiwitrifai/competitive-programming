#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
bool ada[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    ada[a[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
  }

  int one = -1;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 1)
      one = i;
  }
  int ans = 2 * n;
  if (one != -1) {
    bool ok = 1;
    for (int i = one; i < n; ++i) {
      if (b[i] != i - one + 1) {
        ok = 0;
        break;
      }
    }
    int cur = n - one;
    for (int i = 0; i < one; ++i) {
      ++cur;
      if (!ada[cur]) {
        ok = 0;
        break;
      }
      ada[b[i]] = true;
    }
    if (ok) {
      printf("%d\n", one);
      return 0;
    }
  }
  memset(ada, 0, sizeof ada);
  for (int i = 0; i < n; ++i)
    ada[a[i]] = 1;
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    if (ada[cur])
      ++cur;
    ada[b[i]] = true;
  }
  ans = n;
  while (cur <= n) {
    // assert(ada[cur]);
    ++cur;
    ++ans;
  }
  printf("%d\n", ans);
  return 0;
}