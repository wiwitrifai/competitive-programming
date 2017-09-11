#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int cnt[256];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    memset(cnt, 0, sizeof cnt);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - '0']++;
    }
    set<char> ans;
    for (int i = 0; i < 10; i++) {
      if (cnt[i] == 0) continue;
      cnt[i]--;
      for (int j = 0; j < 10; j++) {
        if (cnt[j] == 0) continue;
        char c = i * 10 + j;
        if ('A' <= c && c <= 'Z')
          ans.insert(c);
      }
      cnt[i]++;
    }
    for (char c : ans)
      printf("%c", c);
    printf("\n");
  }
  return 0;
}