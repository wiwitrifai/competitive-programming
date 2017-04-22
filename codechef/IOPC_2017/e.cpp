#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int to[N * 8][62];
int cnt[N * 8], snode;

int enc(char c) {
  if ('0' <= c && c <= '9')
    return c-'0';
  if ('a' <= c && c <= 'z')
    return c-'a' + 10;
  return c-'A' + 36;
}
char dec(int c) {
  if (c < 10) return '0' + 9;
  if (c < 36) return c - 10 + 'a';
  return c - 36 + 'A';
}

void add(string s) {
  int now = 1;
  for (int i = 0; i < s.size(); i++) {
    int c = enc(s[i]);
    if (!to[now][c])
      to[now][c] = ++snode;
    now = to[now][c];
    cnt[now]++;
  }
}
int get(string s) {
  int now = 1;
  for (int i = 0; i < s.size(); i++) {
    int c = enc(s[i]);
    if (!to[now][c])
      return 0;
    now = to[now][c];
  }
  return cnt[now];
}
char str[101], tmp[101];

int dfs(int trie = 1, int now = 0, int id = 0, int rem = 0, int add = 0, int ch = 0) {
  if (now == 8) {
    if (!rem) return 0;
    if (add != 1) return 0; 
    if (ch > 2) return cnt[trie];
    return 0;
  }
  int ret = 0;
  if (add == 0) {
    for (int i = 0; i < 62; i++) {
      if (!to[trie][i]) continue;
      tmp[now] = dec(i);
      ret += dfs(to[trie][i], now+1, id, rem, 1, ch + (tmp[now] != str[now]));
    }
  }
  if (add < 0) add = 0;
  if (!rem)
    ret += dfs(trie, now, id+1, 1, add == 1 ? 1 : -1, ch);
  int c = enc(str[id]);
  if (!to[trie][c]) return ret;
  tmp[now] = str[id];
  ret += dfs(to[trie][c], now+1, id+1, rem, add, ch + (tmp[now] != str[now]));
  return ret;
}
int dfs2(int trie = 1, int now = 0, int ch = 0) {
  if (now == 8) {
    if (ch != 2) return 0;
    return cnt[trie];
  }
  int ret = 0;
  if (ch < 2) {
    int c = enc(str[now]);
    for (int i = 0; i < 62; i++) {
      if (c == i) continue;
      if (!to[trie][i]) continue;
      tmp[now] = dec(i);
      ret += dfs2(to[trie][i], now+1, ch+1);
    }
  }
  int c = enc(str[now]);
  if (!to[trie][c]) return ret;
  tmp[now] = str[now];
  ret += dfs2(to[trie][c], now+1, ch);
  return ret;
}

int main() {
  snode = 1;
  int n, m;
  tmp[0] = 0;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    add(string(str));
  }
  while (m--) {
    int d;
    scanf("%s %d", str, &d);
    if (d == 0)
      printf("%d\n", get(string(str)));
    else if (d == 1) {
      int ans = 0;
      for (int i = 0; i < 8; i++) {
        int c = enc(str[i]);
        for (int j = 0; j < 62; j++) {
          if (j == c) continue;
          str[i] = dec(j);
          ans += get(string(str));
        }
        str[i] = dec(c);
      }
      printf("%d\n", ans);
    }
    else {
      dfs();
      dfs2();
      int ans = dfs() + dfs2();
      printf("%d\n", ans);
    }
  }
  return 0;
}