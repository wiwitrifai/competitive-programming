#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int ok[N][N], vis[N];
char a[N], b[N];

void dfs(int source, int now) {
  if (vis[now]) return;
  vis[now] = 1;
  ok[source][now] = 1;
  for (int i = 0; i < 26; i++) {
    if (ok[now][i]) {
      dfs(source, i);
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 26; i++) ok[i][i] = 1;
  //puts("fuc");
  for (int i = 0; i < n; i++) {
    char s, t;
    scanf(" %c %c", &s, &t);
    ok[s - 'a'][t - 'a'] = 1;
  }
  for (int i = 0; i < 26; i++) {
    memset(vis, 0, sizeof(vis));
    dfs(i, i);
  }
  while (m--) {
    scanf("%s %s", a, b);
    if (strlen(a) != strlen(b)) {
      puts("no");
      continue;
    }
    int len = strlen(a);
    bool can = 1;
    for (int i = 0; i < len; i++) {
      if (!ok[a[i] - 'a'][b[i] - 'a']) can = 0;
    }
    puts(can? "yes" : "no");
  }
  return 0;
}
