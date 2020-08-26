#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];

void solve() {
  int n;
  scanf("%d %s", &n, s);
  int len = n * 2 - 1;
  int mid = len / 2;
  for (int i = 0; i < n; ++i)
    printf("%c", s[mid]);
  printf("\n");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
