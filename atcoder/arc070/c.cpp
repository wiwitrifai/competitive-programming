#include <bits/stdc++.h>

using namespace std;

int main() {
  long long x;
  cin >> x;
  long long ans = 0, sum = 0;
  while (sum < x) {
    sum += ++ans;
  }
  cout << ans << endl;
  return 0;
}