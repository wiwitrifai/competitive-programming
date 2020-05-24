#include <bits/stdc++.h>

using namespace std;

int C(int n, int m) {
  return (n & m) == m;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  n = s.size();
  int one = 0;
  for (int i = 0; i < n; ++i) {
    s[i] -= '1';
    one += s[i] == 1;
  }
  int target = 2;
  if (one) {
    target = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == target)
      ans ^= C(n-1, i);
  }
  ans *= target;
  printf("%d\n", ans);
  return 0;
}
