#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int l = 3, r = n;
  for (int i = 0; i < n; ++i)
    s[i] -= '0';
  while (l < r) {
    int mid = (l + r) >> 1;
    int now = 0;
    for (int i = 0; i < mid; ++i)
      now += s[i];
    bool ok = now >= 3;
    for (int j = mid; j < n; ++j) {
      now += s[j] - s[j-mid];
      ok &= now >= 3;
    }
    if (ok)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}