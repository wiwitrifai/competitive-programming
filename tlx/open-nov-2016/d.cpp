#include <bits/stdc++.h>

using namespace std;

char res[50];

int main() {
  int d, t, n;
  d = t = 0;
  int a, b;
  a = b = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    printf("%d %s\n", i, (a <= b) ? "SAITAMA" : "GENOS");
    fflush(stdout);
    scanf("%s", res);
    if (res[0] == 'S' && res[1] == 'E') {
      if (a < b) {
        d++;
        a++;
      }
      else if (a == b) {
        t++;
      }
      else {
        b++;
        t++;
      }
    }
    else if (res[0] == 'S') {
      if (a < b) {
        d++;
        a++;
        //ga mungkin
      }
      else if (a == b) {
        d++;
        a++;
      }
      else {
        d++;
      }
    }
    else {
      if (a < b) {
        t++;
      }
      else if (a == b) {
        // ga mungkin
        t++;
      }
      else {
        t++;
        b++;
      }
    }
  }
  printf("%d %d\n", d, t);
  fflush(stdout);
  return 0;
}