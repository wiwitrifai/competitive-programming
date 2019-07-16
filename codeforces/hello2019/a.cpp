#include <bits/stdc++.h>

using namespace std;

char s[10][6];

int main() {
  for (int i = 0; i < 6; ++i)
    scanf("%s", s[i]);
  bool ans = 0;
  for (int i = 1; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (s[0][j] == s[i][j])
        ans = 1;
    }
  }
  puts(ans ? "YES" : "NO");
  return 0;
}