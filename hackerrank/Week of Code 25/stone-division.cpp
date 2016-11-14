#include <bits/stdc++.h>

using namespace std;

map< long long, int > grund;

int m;
long long s[20];

int solve(long long n) {
  if (grund.count(n))
    return grund[n];
  set < int > st;
  for (int i = 0; i < m; i++) if ((n % s[i]) == 0) {
    int res = solve(n/s[i]);
    if (s[i] & 1)
      st.insert(res);
    else
      st.insert(0);
  }
  int now = 0;
  for (int v : st)
    now += (now == v);
  grund[n] = now;
  return now;
}

int main() {
  long long n;
  scanf("%lld %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%lld", s+i);
  }
  puts(solve(n) ? "First", "Second");
  return 0;
}