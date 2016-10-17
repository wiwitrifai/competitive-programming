#include <bits/stdc++.h>

using namespace std;

char s[1005];

int  main() {
  scanf("%s", s);
  int n = strlen(s);
  char now = 'a';
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min((26+s[i]-now) % 26, (now + 26 - s[i]) % 26);
    now = s[i];
  }
  printf("%d\n", ans);
  return 0;
}