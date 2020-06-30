#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

void solve() {
  int n;
  scanf("%d %s", &n, s);
  int zero = 0, one = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') break;
    ++zero;
  }
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '0') break;
    ++one;
  }
  if (one + zero < n) {
    ++zero;
  }
  for (int i = 0; i < zero; ++i)
    printf("0");
  for (int i = 0; i < one; ++i)
    printf("1");
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
