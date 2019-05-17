#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    ++cnt[s[0]-'a'];
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    int x = cnt[i]/2;
    ans += x * (x-1) / 2;
    x = cnt[i] - x;
    ans += x * (x-1) / 2;
  }
  printf("%d\n", ans);
  return 0;
}
