#include <bits/stdc++.h>

using namespace std;

int main() {
  long long k, p;
  cin >> p >> k;
  vector<long long > ans;
  set<long long > st;
  while (p >= k || p < 0) {
    if (st.count(p)) {
      puts("-1");
      return 0;
    }
    long long r = p % k;
    if (r < 0) r += k;
    ans.push_back(r);
    long long c = (r-p)/k;
    p = c;
  }
  ans.push_back(p);
  printf("%d\n", ans.size());
  for (long long x : ans)
    printf("%lld ", x);
  puts("");
  return 0;
}