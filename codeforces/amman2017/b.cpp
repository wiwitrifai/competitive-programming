#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N], p[N];
int cnt[256];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", s, p);
    memset(cnt, 0, sizeof cnt);
    int n = strlen(p);
    for (int i = 0; i < n; i++)
      cnt[p[i]]++;
    int ans =0;
    n = strlen(s);
    for (int i = 0; i < n; i++) {
      if (cnt[s[i]] == 0) break;
      ans++;
      cnt[s[i]]--;
    } 
    printf("%d\n", ans);
  }
  return 0;
}