#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
  printf("Q 2 %d %d\n", l, r);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

const int N = 1024;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int x = ask(1, 2), y = ask(2, 3), z = ask(1, 3);
  int tot = (x + y + z)/2;
  a[1] = tot - y, a[2] = tot - z, a[3] = tot - x;
  for (int i = 4; i <= n; i++) {
    a[i] = ask(1, i) - a[1];
  }
  printf("A ");
  for (int i = 1; i <= n; i++)
    printf(" %d", a[i]);
  printf("\n");
  fflush(stdout);
  return 0;
}