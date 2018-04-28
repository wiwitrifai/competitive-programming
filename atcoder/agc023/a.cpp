#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
  map<long long, int> mp;
  mp[0] = 1;
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    sum += x;
    ++mp[sum];
  }
  long long ans = 0;
  for (auto it : mp) {
    long long x = it.second;
    ans += x * (x - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}