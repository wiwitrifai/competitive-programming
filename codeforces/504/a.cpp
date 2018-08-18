#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];
char t[N];

int main() {
  int n, m;
  scanf("%d %d %s %s", &n, &m, s, t);
  bool ok = 1;
  int id = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*')
      id = i;
  }
  if (id == -1) {
    if (n == m) {
      for (int i = 0; i < n; ++i)
        ok &= s[i] == t[i];
    }
    else
      ok = 0;
  }
  else {
    if (n-1 <= m) {
      for (int i = 0; i < id; ++i)
        ok &= s[i] == t[i];
      for (int i = n-1, j = m-1; i > id; --i, --j) {
        ok &= s[i] == t[j];
      }
    }
    else
      ok = 0;
  }
  puts(ok ? "YES" : "NO");
  return 0;
}