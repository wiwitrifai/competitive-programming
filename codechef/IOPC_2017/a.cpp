#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e8 + 7;

char s[N];
int get(int l, int r) {
  if (r-l < 2)
    return 0;
  bool ok = 1;
  for (int i = l+1; i < r; i++)
    if (s[l] != s[i])
      ok = 0;
  if (ok)
    return 0;
  if ((r-l) & 1)
    return inf;
  int mid = (l + r)/2;
  return min(get(l, mid), get(mid, r)) + 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int ans = get(0, strlen(s));
    if (ans >= inf)
      ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}