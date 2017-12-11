#include <bits/stdc++.h>

using namespace std;

void solve(char * s) {
  int a = 0, b = 0, sa = 5, sb = 5;
  for (int i = 0; i < 10; i++) {
    if (i & 1) {
      b += s[i] == '1';
      sb--;
    }
    else {
      a += s[i] == '1';
      sa--;
    }
    if (a > b + sb) {
      printf("TEAM-A %d\n", i+1);
      return;
    }
    if (b > a + sa) {
      printf("TEAM-B %d\n", i+1);
      return;
    }
  }
  for (int i = 10; i < 20; i += 2) {
    a += s[i] == '1';
    b += s[i+1] == '1';
    if (a > b) {
      printf("TEAM-A %d\n", i + 2);
      return;
    }
    if (b > a) {
      printf("TEAM-B %d\n", i + 2);
      return;
    }
  }
  puts("TIE");
}

char s[101];

int main() {
  while (scanf("%s", s) == 1) {
    solve(s);
  }
  return 0;
}