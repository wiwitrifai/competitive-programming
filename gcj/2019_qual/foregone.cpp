#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N], a[N], b[N];

void solve(int tc) {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    if (s[i] == '4') {
      a[i] = b[i] = '2';
    }
    else {
      a[i] = s[i];
      b[i] = '0';
    }
  }
  a[len] = b[len] = 0;
  int offA = 0, offB = 0;
  while (offA + 1 < len && a[offA] == '0') ++offA;
  while (offB + 1 < len && b[offB] == '0') ++offB;
  printf("Case #%d: %s %s\n", tc, a + offA, b + offB);
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