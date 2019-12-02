#include <bits/stdc++.h>

using namespace std;

const int N = 212;

int memo[N][N];
char buff[N];

bool ask(int l, int r) {
  if (l == r)
    return false;
  if (memo[l][r] != -1)
    return memo[l][r];
  printf("? %d %d\n", l, r);
  fflush(stdout);
  scanf("%s", buff);
  memo[l][r] = buff[0] == '<';
  memo[r][l] = !memo[l][r];
  return memo[l][r];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 2 * n; ++i)
      for (int j = 0; j <= 2 * n; ++j)
        memo[i][j] = -1;
    vector<int> node;
    vector<int> to(n * 2 + 1, -1), done(n * 2 + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int u = i, v = n+i;
      if (!ask(u, v))
        swap(u, v);
      node.push_back(u);
      to[u] = v;
    }
    sort(node.begin(), node.end(), ask);
    int big = node.back();
    node.pop_back();
    for (int & x : node)
      x = to[x];
    sort(node.begin(), node.end(), ask);
    if (ask(big, node[0])) {
      printf("!\n");
      fflush(stdout);
      continue;
    }
    done[big] = 1;
    done[to[big]] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
      if (done[i]) continue;
      for (int j = i+1; j <= 2 * n; ++j) {
        if (done[j]) continue;
        ask(i, j);
      }
    }
    printf("!\n");
    fflush(stdout);
  }
  return 0;
}
