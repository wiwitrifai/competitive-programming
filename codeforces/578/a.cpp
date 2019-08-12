#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];
bool ada[10];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == 'L') {
      int now = 0;
      while (now < 10 && ada[now]) ++now;
      ada[now] = 1;
    }
    else if (c == 'R') {
      int now = 9;
      while (now > 0 && ada[now]) --now;
      ada[now] = 1;
    }
    else {
      ada[c-'0'] = 0;
    }
  }
  for (int i = 0; i < 10; ++i)
    printf("%d", ada[i]);
  printf("\n");
  return 0;
}
