#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

int p[N], pos[N];
char ans[N];

void solve(int tc) {
  printf("Case #%d: ", tc);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    pos[p[i]-1] = i;
  }
  p[n] = 0;
  fill(ans, ans+n+1, 0);
  char cur = 'A';
  for (int i = 0; i < n; ++i) {
    int now = pos[i];
    bool fix = 0;
    for (int j = 0; j < n; ++j) {
      if (ans[j] == 0) continue;
      if (p[now+1] < p[j+1])
        cur = max(cur, (char)(ans[j]+1));
    }
    if (cur > 'Z') {
      puts("-1");
      return;
    }
    ans[now] = cur;
  }
  printf("%s\n", ans);
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}