#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], b[N];
vector<long long> val[66];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    long long x;
    scanf("%lld", &x);
    int w = 0;
    while ((1LL << (w+1)) <= x) ++w;
    val[w].push_back(x);
  }
  int len = 0;
  for (int i = 60; i >= 0; --i) {
    for (int j = 0; j < len; ++j)
      a[j] = b[j];
    int k = 0, c = 0;
    bool ok = 1;
    for (int j = 0; j < len; ++j) {
      if (ok && k < val[i].size()) {
        b[c++] = val[i][k++];
        ok ^= 1;
      }
      ok ^= (a[j] >> i) & 1;
      b[c++] = a[j];
    }
    if (ok && k < val[i].size())
      b[c++] = val[i][k++];
    if (k < val[i].size()) {
      puts("No");
      return 0;
    }
    len = c;
  }
  assert(len == n);
  puts("Yes");
  for (int i = 0; i < n; ++i)
    printf("%lld%c", b[i], i+1 == n ? '\n' : ' ');
  return 0;
}