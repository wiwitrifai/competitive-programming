#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], cnt[N];

int main() {
  int n, l, rr;
  scanf("%d %d %d", &n, &l, &rr);
  vector<int> v;
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), v.push_back(a[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
  }
  int r = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    while (r < n && cnt[a[r]] == 0) {
      cnt[a[r]]++;
      r++;
    }
    int len = min(r-i, rr);
    ans += max(len-l+1, 0);
    cnt[a[i]]--;
  }
  printf("%lld\n", ans);
  return 0;
}