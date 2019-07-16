#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
char s[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d %s", &n, s);
    if (n == 2 && s[0] >= s[1]) {
      puts("NO");
    }
    else {
      printf("YES\n2\n%c %s\n", s[0], s+1);
    }
  }
  return 0;
}