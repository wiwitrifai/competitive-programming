#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  int ans1, ans2;
  ans1 = k; ans2 = 1;
  for(int i = 0; i<n; i++) {
    int x; string s;
    cin >> x >> s;
    if(s[0] == 'S') {
      ans2 = max(ans2, x);
    }
    else {
      ans1 = min(ans1, x);
    }
  }
  return 0;
}