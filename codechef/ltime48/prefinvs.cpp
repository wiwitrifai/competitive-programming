#include <bits/stdc++.h>

using namespace std;

char s[20000];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0, now = 0;
  for (int i = n-1; i >= 0; i--) {
    int c = s[i]-'0';
    if (c ^ now) {
      ans++;
      now ^= 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}