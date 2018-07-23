#include <bits/stdc++.h>

using namespace std;

vector<int> vp = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
typedef unsigned long long big;

int main() {
  int k = vp.size();
  int n = 1 << k;
  int sisa = max(int(2e5) - n, 0);
  big m = 1;
  for (int i = 0; i < k; ++i)
    m *= vp[i];
  printf("%d %llu\n", n+sisa, m);
  for (int mask = 0; mask < n; ++mask) {
    big now = 1;
    for (int i = 0; i < k; ++i)
      if ((mask >> i) & 1)
        now *= vp[i];
    printf("%llu\n", now);
  }
  for (int i = 0; i < sisa; ++i)
    printf("%llu\n", m);
  return 0;
}