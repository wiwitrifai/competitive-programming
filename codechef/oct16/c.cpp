#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (now) {
      if (s[i] == 'g')
        ans++;
      now--;
    }
    else {
      if (s[i] == 'p')
        ans--;
      now++;
    }
  }
  printf("%d\n", ans);
  return 0;
}