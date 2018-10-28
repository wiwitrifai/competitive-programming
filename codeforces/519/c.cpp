#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];
int ans[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool rev = 0;
  for (int i = n-1; i >= 0; --i) {
    bool now = s[i] == 'a' ? !rev : rev;
    ans[i] = now;
    if (now)
      rev = !rev;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}