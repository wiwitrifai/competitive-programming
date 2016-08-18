#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N], tmp[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    l--;
    for (int i = l; i < r; i++) {
      tmp[i] = s[i];
    }
    int off = (r-l - k) % (r-l);
    if (off < 0)
      off += r-l;
    for (int i = 0; i < r-l; i++) {
      s[l+i] = tmp[l + ((i + off) % (r-l))];
    }
  }
  printf("%s\n", s);
  return 0;
}