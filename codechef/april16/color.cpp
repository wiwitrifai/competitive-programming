#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d%s", &n, s);
    int r, g, b;
    r = g = b = 0;
    for(int i = 0; i<n; i++) {
      r += s[i] == 'R';
      g += s[i] == 'G';
      b += s[i] == 'B';
    }
    printf("%d\n", n - max(r, max(g, b)));
  }
  return 0;
}