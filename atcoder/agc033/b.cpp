#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

int n;
char s[N], t[N];

bool solve(int h, int c, char lef, char rig) {
  int l = -1, r = h;
  for (int i = n-1; i >= 0; --i) {
    if (t[i] == lef) {
      r = min(r+1, h);
    }
    if (t[i] == rig) {
      l = max(l-1, -1);
    }
    if (s[i] == rig) {
      --r;
    }
    if (s[i] == lef) {
      ++l;
    }
    if (l+1 >= r) {
      return 0;
    }
  }
  if (c <= l || c >= r) {
    return 0;
  }
  return 1;
}

int main() {
  int h, w;
  scanf("%d %d %d", &h, &w, &n);
  int r, c;
  scanf("%d %d", &r, &c);
  scanf("%s", s);
  scanf("%s", t);
  int res = solve(w, c-1, 'L', 'R') && solve(h, r-1, 'U', 'D');
  puts(res ? "YES" : "NO");
  return 0;
}
