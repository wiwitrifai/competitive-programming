#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

int main() {
  vector<int> ans;
  long long now = 3, cur = 2;
  while (now < inf) {
    ans.push_back(now);
    cur *= 2;
    now += cur;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int p = lower_bound(ans.begin(), ans.end(), n) - ans.begin() + 1;
    printf("%d\n", p);
    cur = 1;
    now = n - p - 1;
    for (int i = 0; i < p; ++i) {
      int add = min(cur, now / (p-i));
      printf("%d ", add);
      now -= 1LL * add * (p-i);
      cur += add;
    }
    assert(now == 0);
    printf("\n");
  }
  return 0;
}
