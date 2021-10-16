#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set<int> st;
  int mod = m * 2 - 2;
  auto lantai = [&](int x) {
    if (x < m)
      return x;
    x = x - m;
    x = m - 2 - x;
    return x;
  };
  for (int i = 0; i < n; ++i) {
    int x;
    char c;
    cin >> x >> c;
    --x;
    if (x > 0 && x < m-1 && c == 'D') {
      x = m - 1 + m - 1 - x;
    }
    x %= mod;
    st.insert(x);
  }
  if (st.size() > 2) {
    puts("NO");
    return 0;
  }
  if (st.size() <= 1) {
    puts("YES");
    return 0;
  }
  int u = *st.rbegin(), v = *st.begin();
  for (int i = 0; i < mod; ++i) {
    int a = (u + i) % mod;
    int b = (v + i) % mod;
    if (lantai(a) == lantai(b)) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
