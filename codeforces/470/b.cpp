#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int v[N], t[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <n; ++i)
    scanf("%d", v+i);
  long long offset = 0;
  multiset<long long> val;
  for (int i = 0; i < n; ++i) {
    scanf("%d", t+i);
    long long cur = v[i];
    val.insert(cur + offset);
    long long nxoff = offset + t[i];
    long long melt = 0;
    while (!val.empty() && *val.begin() <= nxoff) {
      auto it = val.begin();
      melt += *it - offset;
      val.erase(it);
    }
    melt += 1LL * val.size() * t[i];
    offset = nxoff;
    printf("%lld ", melt);
  }
  printf("\n");
  return 0;
}