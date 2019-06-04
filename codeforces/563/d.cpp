#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18;
bool used[N];

int a[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  a[0] = 0;
  int len = 1 << n;
  int l = 0;
  int last = 0;
  used[0] = used[x] = 1;
  for (int i = 0; i < len; ++i) {
    if (used[i]) continue;
    a[l++] = last ^ i;
    used[i] = used[i^x] = 1;
    last = i;
  }
  printf("%d\n", l);
  for (int i = 0; i < l; ++i)
    printf("%d%c", a[i], i == l-1 ? '\n' : ' ');
  return 0;
}
