#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char d[] = "NESW";
char s[10020];
int to[256];

int main() {
  for (int i = 0; i < 4; i++)
    to[d[i]] = i;
  scanf("%s", s);
  int n = strlen(s);
  int x, y;
  x = y = 0;
  for (int j = 0; j < n; j++) {
    int c = to[s[j]];
    x += dx[c];
    y += dy[c];
  }
  printf("%d\n", abs(x) + abs(y));
  return 0;
}