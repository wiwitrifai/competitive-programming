#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 6;
char s[N][55];
int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%s", s[i]);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", a+i, b+i);
    a[i]--; b[i]--;
  }
  int now = 0;
  for (int i = m-1; i >= 0; i--) {
    if (a[i] == now) {
      printf("I_love_");
      now = b[i];
    }
  }
  printf("%s\n", s[now]);
  return 0;
}