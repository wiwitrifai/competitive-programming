#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];
int a[N], n, k;

int main() {
  scanf("%d %d %s", &n, &k, s);
  for (int i = 0; i < n; i++)
    a[i] = s[i] == 'A';
  int id = 0, now = -1;
  while (k > 0) {
    if (now == -1) {
      if (id >= n)
        break;
      now = a[id];
      if (id & 1)
        now ^= 1;
      id++;
    }
    now--;
    k--;
  }
  if (k == 0) {
    int cur = 0;
    if (now > -1)
      a[cur++] = now;
    while (id < n) {
      a[cur] = (id-cur) & 1 ? a[id] ^ 1 : a[id];
      cur++, id++;
    }
    while (cur < n) {
      a[cur] = (n-cur) & 1;
      cur++;
    }
  }
  else {
    if (now == -1) {
      now = n & 1;
    }
    a[0] = now;
    for (int i = 1; i < n; i++)
      a[i] = (n-i) & 1;
    if (n & 1) {
      if (k & 1)
        a[0] ^= 1;
    }
  }
  for (int i = 0; i < n; i++)
    printf("%c", a[i] ? 'A' : 'B');
  printf("\n");
  return 0;
}