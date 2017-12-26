#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool can[26], tmp[26];
char cmd[N], s[N];

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  int cnt = 26;
  for (int i = 0; i < 26; ++i) can[i] = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%s %s", cmd, s);
    if (i == n-1) break;
    if (cnt <= 1) {
      ans += cmd[0] == '?' || cmd[0] == '!';
      continue;
    }
    if (cmd[0] == '.') {
      int len = strlen(s);
      for (int j = 0; j < len; ++j) {
        if (can[s[j]-'a']) cnt--;
        can[s[j]-'a'] = 0;
      }
    }
    else if (cmd[0] == '!') {
      for (int j = 0; j < 26; ++j)
        tmp[j] = 0;
      int len = strlen(s);
      for (int j = 0; j < len; ++j) {
        tmp[s[j]-'a'] = 1;
      }
      for (int j = 0; j < 26; ++j) {
        if (tmp[j]) continue;
        if (can[j]) cnt--;
        can[j] = 0;
      }
    }
    else {
      if (can[s[0]-'a']) cnt--;
      can[s[0]-'a'] = 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}