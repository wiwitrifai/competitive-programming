#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

// int lis[N], lcs[N];
int ans[N];
int main() {
  int n;
  scanf("%d", &n);
  // map<pair<int, int>, vector<int> > mp;
  // vector<int> v;
  // for (int i = 0; i < n; ++i)
  //   v.push_back(i);
  // do {
  //   int a = 0, b = 0;
  //   for (int i = 0; i < n; ++i) {
  //     int r = lower_bound(lis, lis+a, v[i]) - lis;
  //     lis[r] = v[i];
  //     a += r == a;
  //     r = lower_bound(lcs, lcs+b, -v[i]) - lcs;
  //     lcs[r] = -v[i];
  //     b += r == b;
  //   }
  //   mp[make_pair(a, b)] = v;
  // } while (next_permutation(v.begin(), v.end()));
  // for (auto it : mp) {
  //   cout << it.first.first << " & " << it.first.second << endl;
  //   for (int x : it.second)
  //     cout << x << " ";
  //   cout << endl;
  // }
  int a, b;
  scanf("%d %d", &a, &b);
  if (a + b > n+1) {
    puts("-1");
    return 0;
  }
  if ((n + a - 1) / a > b) {
    puts("-1");
    return 0;
  }
  int k = 0;
  while (1) {
    int cnt = k + (n-k + a-1)/a;
    if (cnt >= b)
      break;
    ++k;
  }
  int now = 0;
  for (int i = 0; i < k; ++i)
    ans[i] = n-i;
  for (int i = n-1; i >= k; i -= a) {
    for (int j = max(k, i-a+1); j <= i; ++j)
      ans[j] = ++now;
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  return 0;
}