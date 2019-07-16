#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];

int main() {
  scanf("%s", s);
  int ans = 1, cnt = 0;
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'a') {
      cnt = 0;
    }
    else
      ++cnt;
    ans = max(ans, cnt+1);
  }
  while (ans--)
    printf("a");
  printf("\n");
  return 0;
}