#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int r = 0, b = 0;
  for (int i = 0; i < n; ++i)
    r += s[i] == 'R';
  b = n - r;
  puts(r > b ? "Yes" : "No");
  return 0;
}
