#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char p[N], ans[N];

void solve(int tc) {
  int n;
  scanf("%d", &n);
  scanf("%s", p);
  int len = strlen(p);
  assert(len == (2 * n - 2));
  int s = 0, e = 0;
  int ps = 0, pe = 0;
  for (int i = 0; i < len; ++i) {
    if (p[i] == 'S')
      ++ps;
    else
      ++pe;
    if (s == e) {
      if (ps - pe < 0) {
        ans[i] = 'S';
        ++s;
      }
      else {
        ans[i] = 'E';
        ++e;
      }
    }
    else if (e > s) {
      ans[i] = 'S';
      ++s;
    }
    else {
      ans[i] = 'E';
      ++e;
    }
  }
  assert(e == (n-1) && s == e);
  ans[len] = 0;
  printf("Case #%d: %s\n", tc, ans);
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