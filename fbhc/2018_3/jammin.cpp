#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];

void solve(int tc) {
  printf("Case #%d: ", tc);
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0, cur = 0;
  s[n] = '#';
  s[n+1] = '#';
  s[n+2] = '#';
  s[n+3] = '#';
  int pagar = 0;
  int simpan = 0;
  bool last = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '#' && s[i+1] == '#' && s[i+2] == '#') break;
    if (s[i] == '*') {
      ++cur;
      if (cur > 1 || (last && cur > 0)) {
        cur += simpan;
        simpan = 0;
      }
    }
    else if (s[i] == '#') {
      if (s[i+1] == '#') {
        if (s[i+2] != '*') break;
        if (cur == 0) break;
        last = false;
        ++pagar;
        i += 2;
      }
      else if (s[i+1] == '*') {
        // nothing
        last = false;
      }
      else {
        if (cur == 0) break;
        else if (cur == 1) {
          ++simpan;
          --cur;
          last = 1;
        }
        else {
          // nothing
        }
      }
    }
    // cerr << i << " " << cur << " " << simpan << endl;
    ans = max(ans, cur);
  }
  ans = max(ans, cur);
  printf("%d\n", ans);
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
    fflush(stdout);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}