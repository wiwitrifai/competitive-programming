#include <bits/stdc++.h>

using namespace std;

long long solve(long long n, long long a, long long b, long long c, long long d) {
  if (a == c) {
    long long le = b + (d-b-1)/2, ri = (n+1-d) + (d-b-1)/2;
    if (le + ri < n) le++;
    assert(le + ri == n);
    return ri - le;
  } else {
    if (b == d) return 0;
    long long le = b, ri = n+1-d;
    long long val = ri-le;
    if (d-b-1 == 0) {
      if (val < 0) return -1;
      return 0;
    }
    if ((d-b-1) % 2) {
      if (val <= -2)
        return -1;
      if (val >= 2) return 1;
      return 0;
    }
    else {
      if (val >= 3) return 1;
      if (val >= 0) return 0;
      return -1;
    }
  }
}

int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    assert(a != c || b != d);
    if (b > d) {
      b = n+1 - b;
      d = n+1 - d;
    }
    long long ans = solve(n, a, b, c, d);
    if (ans < 0)
      puts("Miron");
    else if (ans > 0)
      puts("Slava");
    else
      puts("Draw");
  }

  return 0;
}