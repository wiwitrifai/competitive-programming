#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long sum = 0;
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i), sum += a[i];
    for (int i = 0; i < m; ++i)
      scanf("%d", b+i), sum += b[i];
    int x = max(n, m);
    for (int i = n; i < x; ++i)
      a[i] = 0;
    for (int i = m; i < x; ++i)
      b[i] = 0;
    sort(a, a+x);
    sort(b, b+x);
    bool same = 1;
    for (int i = 0; i < x; ++i) {
      same &= a[i] == b[i];
    }
    puts(same ? "Bob" : "Alice");
  }
  return 0;
}