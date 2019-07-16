#include <bits/stdc++.h>

using namespace std;

int cnt[30];
char s[1000];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; ++i)
    ++cnt[s[i]-'0'];
  int ans = min(n/11, cnt[8]);
  printf("%d\n", ans);
  return 0;
}