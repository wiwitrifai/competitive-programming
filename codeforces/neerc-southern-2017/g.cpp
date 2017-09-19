#include <bits/stdc++.h>

using namespace std;

int cnt[10];
char s[10000];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < 7; j++)
      cnt[j] += s[j] == '1';
  }
  int ans = 0;
  for (int i = 0; i < 7; i++)
    ans = max(ans, cnt[i]);
  printf("%d\n", ans);
  return 0;
}