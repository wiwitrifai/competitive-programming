#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

char vows[] = "aiueo";

bool vowel(char c) {
  for (int i = 0; i < 5; ++i)
    if (c == vows[i])
      return true;
  return false;
}

int main() {
  scanf("%s", s);
  int cnt = 0;
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    cnt += vowel(s[i]);
  }
  if (cnt == 0)
    puts("1");
  else {
    if (!vowel(s[0])) {
      puts("0");
      return 0;
    }
    cnt = (cnt + 1) / 2;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      if (vowel(s[i])) {
        --cnt;
      }
      else {
        if (cnt == 0)
          ++ans;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}