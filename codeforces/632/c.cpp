#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  map<long long, int> last;
  long long sum = 0;
  last[sum] = -1;
  long long ans = 0;
  int pre = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    sum += x;
    auto it = last.find(sum);
    if (it != last.end()) {
      pre = max(it->second+1, pre);
    }
    ans += i - pre;
    last[sum] = i;
  }
  printf("%lld\n", ans);
  return 0;
}
