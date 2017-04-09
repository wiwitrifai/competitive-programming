#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];
int n, k;

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%s %d", s, &k);
    n = strlen(s);
    int ans = 0;
    for (int i = 0; i + k <= n; i++) {
      if (s[i] == '+') continue;
      ans++;
      for (int j = 0; j < k; j++) {
        if (s[i+j] == '-')
          s[i+j] = '+';
        else
          s[i+j] = '-';
      }
    }
    bool ok = 1;
    for (int i = 0; i < n; i++)
      if (s[i] == '-')
        ok = 0;
    if (ok)
      printf("Case #%d: %d\n", tc, ans);
    else
      printf("Case #%d: IMPOSSIBLE\n", tc);
    cerr << "Case #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl; 
  }
  return 0;
}