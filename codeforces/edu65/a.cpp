#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    bool ok = 0;
    for (int i = 0; i + 11 <= n; ++i) {
      if (s[i] == '8')
        ok = 1;
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
