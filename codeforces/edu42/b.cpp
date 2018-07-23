#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int n, a, b;

int main() {
  scanf("%d %d %d", &n, &a, &b);
  scanf("%s", s);
  int last = -1, ans = 0;
  for (int i = 0; i < n && a+b > 0 ; ++i) {
    if (s[i] == '*') {
      last = -1;
      continue;
    }
    if (last == -1) {
      if (a > b) {
        --a;
        ++ans;
        last = 0;
      }
      else {
        --b;
        ++ans;
        last = 1;
      }
    }
    else if (last == 0) {
      if (b > 0) {
        --b;
        ++ans;
        last = 1;
      }
      else
        last = -1;
    }
    else {
      if (a > 0) {
        --a;
        ++ans;
        last = 0;
      }
      else
        last = -1;
    }
  }
  printf("%d\n", ans);
  return 0;
}