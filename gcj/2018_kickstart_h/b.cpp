#include <bits/stdc++.h>

using namespace std;


const int N = 5e6 + 6;

char s[N];
void solve(int tc) {
  int n;
  scanf("%d %s", &n, s);
  int ans = 0, sum = 0;
  int len = (n+1) / 2;
  for (int i = 0; i < n; ++i) {
    s[i] -= '0';
    sum += s[i];
    if (i >= len)
      sum -= s[i-len];
    ans = max(ans, sum);
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