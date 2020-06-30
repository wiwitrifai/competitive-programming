#include <bits/stdc++.h>

using namespace std;

bool solve(int n) {
  if (n == 2) {
    return true;
  }
  int dua = 0;
  while ((n % 2) == 0) {
    n /= 2;
    ++dua;
  }
  bool found = 0;
  for (long long i = 2; !found && i * i <= n; ++i) {
    found |= (n % i) == 0;
  }
  if ((n == 1) || (dua == 1 && !found))
    return false;
  else
    return true;
}


void check(int n) {
  vector<int> grund(n+1);
  for (int i = 2; i <= n; ++i) {
    set<int> st;
    st.insert(grund[i-1]);
    for (int x = 3; x <= i; x += 2) {
      if (i % x) continue;
      st.insert(grund[i/x]);
    }
    grund[i] = 0;
    for (int x : st)
      grund[i] += grund[i] == x;
  }
  for (int i = 1; i <= n; ++i)
    assert(solve(i) == !!grund[i]);
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    puts(solve(n) ? "Ashishgup" : "FastestFinger");
  }
  return 0;
}
