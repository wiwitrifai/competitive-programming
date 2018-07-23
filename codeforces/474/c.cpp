#include <bits/stdc++.h>

using namespace std;

int main() {
  long long x, d;
  cin >> x >> d;
  vector<long long> ans;
  long long now = 1;
  long long c = 0;
  while (c < x) {
    long long v = 1;
    while ((c + (1LL << (v+1)) - 1) <= x) ++v;
    c += (1LL << v) - 1;
    for (int i = 0; i < v; ++i)
      ans.push_back(now);
    now += d+1;
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    if (i) printf(" ");
    printf("%lld", ans[i]);
  }
  printf("\n");
  return 0;
}