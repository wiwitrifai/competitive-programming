#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int mask[N];

int main() {
  int n;
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    int now = 0;
    if (s[i] == 'A')
      now = 1;
    else if (s[i] == 'B')
      now = 2;
    else if (s[i] == 'C')
      now = 4;
    for (int j = max(i-1, 0); j <= min(i+1, n-1); ++j) {
      mask[j] |= now;
    }
  }
  bool ok = 0;
  for (int i = 0; i < n; ++i)
    if (mask[i] == 7)
      ok = 1;
  puts(ok ? "Yes" : "No");
  return 0;
}

