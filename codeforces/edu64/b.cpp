#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];
int cnt[26];

bool used[N];
char order[N];

int c;

bool dfs(int id) {
  if (id == c) {
    for (int i = 0; i < c; ++i) {
      for (int j = 0; j < cnt[order[i]-'a']; ++j) {
        printf("%c", order[i]);
      }
    }
    printf("\n");
    return true;
  }
  // cerr << id << endl;
  // for (int i = 0; i < id; ++i) {
  //   cerr << order[i];
  // }
  // cerr << endl;
  for (int i = 0; i < 26; ++i) {
    if (used[i] || cnt[i] == 0) continue;
    order[id] = 'a' + i;
    if (id > 0 && abs(order[id]-order[id-1]) == 1) continue;
    used[i] = 1;
    bool res = dfs(id+1);
    used[i] = 0;
    if (res)
      return true;
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
      ++cnt[s[i]-'a'];
    }
    memset(used, 0, sizeof used);
    c = 0;
    for (int i = 0; i < 26; ++i)
      c += cnt[i] > 0;
    if (!dfs(0)) {
      puts("No answer");
    }
  }
  return 0;
}
