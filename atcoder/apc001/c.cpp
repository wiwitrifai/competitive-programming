#include <bits/stdc++.h>

using namespace std;


char s[20];
int ask(int x) {
  printf("%d\n", x);
  fflush(stdout);
  scanf("%s", s);
  if (s[0] == 'V')
    return 0;
  else if (s[0] == 'M')
    return 1;
  else
    return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  int res = ask(0);
  if (!res) return 0;
  int le = 1, ri = n-1;
  while (le < ri) {
    int mid = (le + ri) >> 1;
    int val = ask(mid % n);
    if (!val) return 0;
    if ((mid - le) & 1) {
      if (val == res)
        le = mid+1;
      else
        ri = mid-1;
    }
    else {
      if (val == res)
        ri = mid-1;
      else
        le = mid+1, res = val;
    }
  }
  assert(ask(le % n) == 0);
  return 0;
}