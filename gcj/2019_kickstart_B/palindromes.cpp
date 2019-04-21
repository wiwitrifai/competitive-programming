#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int cnt[N][26];

void solve(int tc) {
  int n, q;
  scanf("%d %d", &n, &q);
  int ans = 0;
  scanf("%s", s);
  for (int i = 0; i < 26; ++i)
    cnt[0][i] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j)
      cnt[i+1][j] = cnt[i][j];
    cnt[i+1][s[i]-'A']++;
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    int cur = 0;
    for (int i = 0; i < 26; ++i) {
      cur += (cnt[r][i] - cnt[l][i]) & 1;
    }
    ans += (cur <= 1);
  }
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
