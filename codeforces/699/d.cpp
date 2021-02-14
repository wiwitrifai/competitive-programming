#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N][N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  if (m & 1) {
    puts("YES");
    for (int i = 0; i <= m; ++i) {
      printf("%d%c", 1 + (i & 1), i == m ? '\n' : ' ');
    }
    return;
  }
  int a = -1, b = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (s[i][j] == s[j][i]) {
        a = i;
        b = j;
      }
    }
  }
  if (a != -1 && b != -1) {
    puts("YES");
    for (int i = 0; i <= m; ++i) {
      printf("%d%c", (i & 1) ? a+1 : b+1, i == m ? '\n' : ' ');
    }
    return;
  }
  if (n == 2) {
    puts("NO");
    return;
  }
  vector<int> p = {0, 1, 2};
  int c = -1;
  do {
    if (s[p[0]][p[1]] == s[p[1]][p[2]]) {
      a = p[0];
      b = p[1];
      c = p[2];
      break;
    }
  } while (next_permutation(p.begin(), p.end()));
  int half = m / 2;
  vector<int> ans;
  ans.push_back(b);
  for (int i = 0; i < half; ++i) {
    ans.push_back((i & 1) ? b : a);
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < half; ++i) {
    ans.push_back((i & 1) ? b : c);
  }
  puts("YES");
  for (int i = 0; i <= m; ++i) {
    printf("%d%c", ans[i]+1, i == m ? '\n' : ' ');
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
