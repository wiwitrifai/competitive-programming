#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
char a[N], b[N];

int main() {
  int n = 0;
  int m = 1;
  scanf("%d", &n);
  a[0] = '1';
  while (n--) {
    a[m] = '\0';
    printf("%s%c", a, n ? ' ' : '\n');
    char last = a[0];
    char cnt = '1';
    int now = 0;
    for (int i = 1; i < m; i++) {
      if (a[i] == last) {
        cnt++;
      }
      else {
        b[now++] = cnt;
        b[now++] = last;
        last = a[i];
        cnt = '1';
      }
    }
    b[now++] = cnt;
    b[now++] = last;
    m = now;
    for (int i = 0; i < m; i++)
      a[i] = b[i];
  }
  return 0;
}