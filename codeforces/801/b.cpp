#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  if (n & 1) {
    cout << "Mike\n";
  } else {
    long long sum[2];
    sum[0] = sum[1] = 0;
    for (int i = 0; i < 2; ++i) {
      int mini = a[i];
      for (int j = i; j < n; j += 2) {
        mini = min(mini, a[j]);
      }
      sum[i] = 1LL * mini * (n / 2);
      for (int j = i; j < n; j += 2) {
        if (a[j] <= mini) break;
        ++sum[i];
      }
    }
    if (sum[0] <= sum[1]) {
      cout << "Joe\n";
    } else {
      cout << "Mike\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
