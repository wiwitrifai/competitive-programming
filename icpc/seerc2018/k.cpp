#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ui64;

ui64 calc(ui64 n) {
  ui64 a[3] = {n, n+1, n+2};
  for (int j = 2; j <= 3; ++j) {
    for (int i = 0; i < 3; ++i) {
      if (a[i] % j) continue;
      a[i] /= j;
      break;
    }
  }
  ui64 ret = 1;
  for (int i = 0; i < 3; ++i)
    ret *= a[i];
  return ret;
}

int main() {
  int a, b, c;
  ui64 n;
  cin >> a >> b >> c >> n;
  set<int> st;
  st.insert(a);
  st.insert(b);
  st.insert(c);
  ui64 ans = 0;
  if (n <= 2) {
    puts("0");
    return 0;
  }
  if (n & 1) {
    n /= 2;
    ui64 s = n * (n + 1) / 2;
    s *= n;
    ui64 r = calc(n-1);
    ans = s - r;
  }
  else {
    n /= 2;
    ui64 s = (n+2) * (n - 1) / 2 + n-1;
    s *= n;
    ui64 r = calc(n) - n;
    ans = s - r;
  }
  if (st.size() == 3)
    ans *= 6;
  else if (st.size() == 2)
    ans *= 3;
  cout << ans << endl;
  return 0;
}