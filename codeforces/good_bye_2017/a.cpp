#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N];

bool cek(char c) {
  if (c <= 'z' && c >= 'a') {
    return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
  }
  else {
    int d = c - '0';
    return d & 1;
  }
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += cek(s[i]);
  }
  printf("%d\n", ans);
  return 0;
}