#include <bits/stdc++.h>

using namespace std;

const int N = 200;

char s[N];
int n, k;
int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  bool ok = 1, exact = 0;

  for (int i = 0; i < n; i++) {
    if (i + k + 1 > n) break;
    bool now = 0;
    for (int j = 0; j < k+1; j++) {
      if (s[i+j] != 'N')
        now = 1;
    }
    if (!now) {
      puts("NO");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i + k > n) break;
    bool now = 1;
    if (i && s[i-1] == 'N') now = 0;
    if (i + k < n && s[i+k] == 'N') now = 0;
    for (int j = 0; j < k; j++)
      if (s[i+j] == 'Y')
        now = 0;
    if (now)
      exact = 1;
  }
  if (exact)
    puts("YES");
  else
    puts("NO");
  return 0;
}