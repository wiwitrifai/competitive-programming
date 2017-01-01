#include <bits/stdc++.h>

using namespace std;

char s[1000];

int main() {
  int n;
  scanf("%d", &n);
  int now = 0;
  bool ans = 1;
  while (n-- && ans) {
    int d;
    scanf("%d %s", &d, s);
    if (now == 20000) {
      if (s[0] != 'N') {
        ans = 0;
        break;
      }
    }
    if (now == 0) {
      if (s[0] != 'S') {
        ans = 0;
        break;
      }
    }
    if (s[0] == 'S') {
      now += d;
      if (now > 20000) {
        ans = 0;
        break;
      }
    }
    else if (s[0] == 'N') {
      now -= d;
      if (now < 0) {
        ans = 0;
        break;
      }
    }
  }
  if (now != 0)
    ans = 0;
  puts(ans ? "YES" : "NO");
  return 0;
}