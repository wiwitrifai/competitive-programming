#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
vector<int> pos[26];
int cnt[26];
char t[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; ++i) {
    s[i] -= 'a';
    pos[s[i]].push_back(i+1);
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int ans = 0;
    scanf("%s", t);
    int len = strlen(t);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < len; ++i) {
      t[i] -= 'a';
      ++cnt[t[i]];
    }
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] == 0) continue;
      ans = max(ans, pos[i][cnt[i]-1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
