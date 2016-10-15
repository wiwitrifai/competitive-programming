#include <bits/stdc++.h>

using namespace std;

const int N = 128;
char s[N][N];
int len[N], a[N];
int g[30][30], to[30], vis[30];
char ans[30];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i]--;
  }
  memset(g, 0, sizeof g);
  bool ok = true;
  for (int ii = 0; ii < n && ok; ii++) {
    for (int jj = ii+1; jj < n; jj++) {
      int i = a[ii], j = a[jj];
      int k = 0;
      while (s[i][k] == s[j][k] && k < len[i]) k++;
      if (s[i][k] && s[j][k]) {
        int a = s[i][k] - 'a', b = s[j][k] - 'a';
        if (g[a][b] == 1) {
          ok = false;
          break;
        }
        g[b][a] = 1;
        g[a][b] = -1;
      }
    }
  }
  if (!ok) {
    puts("NE");
    return 0;
  }
  stack < int > st;
  for (int i = 25; i >= 0; i--) {
    to[i] = 0;
    for (int j = 0; j < 26; j++) if (g[i][j] == 1) {
      to[i]++;
    }
    if (to[i] == 0)
      st.push(i);
  }
  int nans = 0;
  while (!st.empty()) {
    int top = st.top();
    st.pop();
    ans[top] = 'a' + nans++;
    for (int j = 0; j < 26; j++) if (g[top][j] == -1) {
      to[j]--;
      if (to[j] == 0) {
        st.push(j);
      }
    }
  }
  if (nans != 26)
    puts("NE");
  else {
    ans[26] = '\0';
    puts("DA");
    printf("%s\n", ans);
  }
  return 0;
}