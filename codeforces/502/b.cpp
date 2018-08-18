#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s%s", a, b);
  int one = 0, zero = 0, onec = 0, zeroc = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '0') {
      if (b[i] == '0')
        ++zeroc;
      else
        ++zero;
    }
    else {
      if (b[i] == '0')
        ++onec;
      else
        ++one;
    }
  }
  long long ans = 1LL * zeroc * one + 1LL * onec * zero + 1LL * zeroc * onec;
  cout << ans << endl;
  return 0;
}