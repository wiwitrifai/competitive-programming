#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];
char ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    bool ok = 1;
    for (int i = 0; i < n; ++i)
      ans[i] = 'B';
    int l = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') continue;
      while (l < i && s[l] == ')') ++l;
      if (l == i) {
        ans[i] = 'R';
      }
      else {
        ++l;
      }
    }
    while (l < n) {
      if (s[l] == '(')
        ans[l] = 'R';
      ++l;
    }
    l = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(' || ans[i] != 'R') continue;
      while (l < i && s[l] == ')') ++l;
      if (l == i) {
        ok = 0;
        break;
      }
      else {
        ans[l] = 'G';
        ++l;
      }
    }
    l = n-1;
    for (int i = n-1; i >= 0; --i) {
      if (s[i] == ')' || ans[i] != 'R') continue;
      while (l > i && s[l] == '(') --l;
      if (l == i) {
        ok = 0;
        break;
      }
      else {
        ans[l] = 'G';
        --l;
      }
    }
    if (ok) {
      ans[n] = 0;
      printf("%s\n", ans);
    }
    else
      puts("impossible");
  }
  return 0;
}