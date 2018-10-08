#include <bits/stdc++.h>

using namespace std;

const int N = 66;

int a[N];
char s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int p;
  scanf("%d %s", &p, s); --p;
  int ans0 = 0, ans1 = 0;
  if (s[0] == 'l') {
    for (int i = p; i >= 0; --i)
      ans0 += a[i];
  }
  else {
    for (int i = p; i < n; ++i)
      ans0 += a[i];
  }
  scanf("%d %s", &p, s); --p;
  if (s[0] == 'l') {
    for (int i = p; i >= 0; --i)
      ans1 += a[i] == 0;
  }
  else {
    for (int i = p; i < n; ++i)
      ans1 += a[i] == 0;
  }
  printf("%d %d\n", ans0, ans1);
  return 0;
}