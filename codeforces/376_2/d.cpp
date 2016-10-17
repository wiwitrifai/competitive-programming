#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int s[2][N], m[2];
int cnt[N];

int  main() {
  int n, k;
  scanf("%d %d", &n, &k);
  bool ok = true;
  int all = 0;
  for (int i = 0; i < n; i++) {
    int c = i & 1, b = !c;
    scanf("%d", &m[c]);
    for (int j = 0; j < m[c]; j++)
      scanf("%d", s[c]+j);
    s[c][m[c]] = 0;
    if (i) {
      int j = 0;
      while (j < m[b] && s[c][j] == s[b][j]) j++;
      if (s[b][j] == 0)
        continue;
      if (s[c][j] == 0) {
        ok = false;
        break;
      }
      cnt[s[c][j]]++;
      cnt[s[b][j]]--;
      all++;
      if (s[b][j] < s[c][j]) {
        cnt[1]++;
      }
    }
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  int sum = 0;
  ok = false;
  for (int i = 1; i <= k; i++) {
    sum += cnt[i];
    // cerr << i << " " << sum << endl;
    if (sum == all) {
      printf("%d\n", k-i);
      ok = true;
      break;
    }
  }
  if (!ok)
    puts("-1");
  return 0;
}