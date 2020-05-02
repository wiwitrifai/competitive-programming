#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> pos(n, -1);
  {
    pos[0] = 0;
    int i = 0;
    while (i * 2 < n) {
      pos[i] = i * 2;
      ++i;
    }
    int j = 1;
    bool ok = 1;
    for (int k = 0; k < i; ++k) {
      int dr = abs(k - i), dc = abs(k * 2 - j);
      if (dr == dc || dr == 0 || dc == 0) {
        ok = false;
        break;
      }
    }
    int til = n;
    if (!ok)
      ++i;
    else
      --til;
    while (j < n && i < til) {
      pos[i++] = j;
      j += 2;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += pos[i] == -1;
  }
  assert(cnt == 1);
  for (int i = 0; i < n; ++i) {
    if (pos[i] == -1) continue;
    for (int j = i+1; j < n; ++j) {
      if (pos[j] == -1) continue;
      int dr = abs(i-j), dc = abs(pos[i] - pos[j]);
      assert(dr != 0 && dc != 0 && dr != dc);
    }
  }
  vector<string> ans(n, string(n, '.'));
  for (int i = 0; i < n; ++i) {
    if (pos[i] != -1)
      ans[i][pos[i]] = '*';
    printf("%s\n", ans[i].c_str());
  }
  return 0;
}
