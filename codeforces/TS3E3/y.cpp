#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int n, t, e;
vector< int > p[N];
int ans[N];

int main() {
  scanf("%d %d %d", &n, &t, &e);
  for (int i = 0; i < e; i++) {
    int h, pp;
    scanf("%d %d", &h, &pp);
    p[h].push_back(pp);
  }
  bool pos = true;
  for (int i = 1; i <= n; i++) {
    int sz = p[i].size();
    sort(p[i].begin(), p[i].end());
    ans[i] = 0;
    if (i == t)
      continue;
    for (int j = (int)sz - 1; j >= 0 && sz > 0; j--) {
      ans[i]++;
      sz -= p[i][j];
      if (sz <= 0)
        break;
    }
    if (sz > 0) {
      cerr << i << " " << sz << endl;
      pos = false;
      break;
    }
  }
  if (pos) {
    for (int j = 1; j <= n; j++)
      printf("%d ", ans[j]);
    printf("\n");
  }
  else
    puts("IMPOSSIBLE");
  return 0;
}