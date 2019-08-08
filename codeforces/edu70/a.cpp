#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N], p[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", s, p);
    int n = strlen(s);
    int m = strlen(p);
    reverse(p, p+m);
    reverse(s, s+n);
    int pos = 0;
    while (p[pos] == '0') ++pos;
    int ans = 0;
    while (s[pos + ans] == '0') ++ans;
    printf("%d\n", ans);
  }
  return 0;
}
