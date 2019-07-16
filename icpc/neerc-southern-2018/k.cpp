#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    sum += a[i];
  }
  if (sum % k) {
    puts("No");
    return 0;
  }
  sum /= k;
  bool ok = 1;
  vector<int> ans;
  long long cur = 0;
  int last = -1;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    if (cur == sum) {
      cur = 0;
      ans.push_back(i - last);
      last = i;
    }
    if (cur > sum) {
      ok = 0;
      break;
    }
  }
  if (cur != 0)
    ok = 0;
  if (ok) {
    puts("Yes");
    assert(ans.size() == k);
    for (int i = 0; i < k; ++i) {
      printf("%d%c", ans[i], i == k-1 ? '\n' : ' ');
    }
  }
  else
    puts("No");
  return 0;
}