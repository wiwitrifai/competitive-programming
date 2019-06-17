#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

char s[N];

void solve(int tc) {
  printf("Case #%d: ", tc);
  scanf("%s", s);
  int n = strlen(s);
  int b = 0, e = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == 'B')
      ++b;
    else
      ++e;
  }
  if (e == 0) {
    puts(n == 1 ? "Y" : "N");
    return;
  }
  if (b == 1) {
    puts(e == 1 ? "Y" : "N");
    return;
  }
  puts(b >= 2 ? "Y" : "N");
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
