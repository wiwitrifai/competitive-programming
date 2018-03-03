#include <bits/stdc++.h>

using namespace std;

string ans[] = {"LB", "MB", "UB", "SLB", "SUB"};

int main() {
  int n;
  scanf("%d", &n); --n;
  n %= 8;
  if (n < 6) {
    cout << ans[n % 3] << endl;
  }
  else {
    n -= 6;
    cout << ans[3 + (n % 2)] << endl;
  }
  return 0;
}