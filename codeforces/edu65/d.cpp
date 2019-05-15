#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int depth = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      printf("%d", depth & 1);
      ++depth;
    }
    else {
      --depth;
      printf("%d", depth & 1);
    }
  }
  printf("\n");
  return 0;
}
