#include <bits/stdc++.h>

using namespace std;

const int N = 105, M = 2e4 + 5;;

char s[N][N];
int r[N], c[N], n, m;
char cmd[M];

bool ishor(char ch) {
  return ch == 'L' || ch == 'R'; 
}

void change(char bef, char cur) {
  if (ishor(cur) == ishor(bef)) return;
  if (ishor(cur)) {
    fill(r, r+n, 0);
    for (int i = 0; i < m; ++i)
      if (c[i] > 0)
        ++r[c[i]-1];
    for (int i = n-1; i > 0; --i) {
      r[i-1] += r[i];
    }
    if (bef == 'D')
      reverse(r, r+n);      
  }
  else {
    fill(c, c+m, 0);
    for (int i = 0; i < n; ++i)
      if (r[i] > 0)
        ++c[r[i]-1];
    for (int i = m-1; i > 0; --i) {
      c[i-1] += c[i];
    }
    if (bef == 'R')
      reverse(c, c+m);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
    }
    scanf("%s", cmd);
    int len = strlen(cmd);
    if (ishor(cmd[0])) {
      for (int i = 0; i < n; ++i) {
        r[i] = 0;
        for (int j = 0; j < m; ++j)
          r[i] += s[i][j] == '1';
      }
    }
    else {
      for (int j = 0; j < m; ++j) {
        c[j] = 0;
        for (int i = 0; i < n; ++i)
          c[j] += s[i][j] == '1';
      }
    }
    char last = 0;
    for (int it = 1; it < len; ++it) {
      char bef = cmd[it-1], cur = cmd[it];
      if (ishor(cur) == ishor(bef)) continue;
      change(bef, cur);
      last = cur;
      break;
    }
    if (last) {
      char h, v;
      for (int i = 0; i < len; ++i)
        if (ishor(cmd[i]))
          h = cmd[i];
        else
          v = cmd[i];
      if (ishor(cmd[len-1]))
        swap(h, v);
      change(last, h);
      change(h, v);
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        s[i][j] = '0';
    if (ishor(cmd[len-1])) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < r[i]; ++j)
          s[i][j] = '1';
      if (cmd[len-1] == 'R')
        for (int i = 0; i < n; ++i)
          reverse(s[i], s[i]+m);
    }
    else {
      for (int j = 0; j < m; ++j)
        for (int i = 0; i < c[j]; ++i)
        s[i][j] = '1';
      if (cmd[len-1] == 'D') {
        for (int i = 0, k = n-1; i < k; ++i, --k) {
          for (int j = 0; j < m; ++j)
            swap(s[i][j], s[k][j]);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      s[i][m] = '\0';
      printf("%s\n", s[i]);
    }
  }

  return 0;
}