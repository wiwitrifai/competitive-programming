#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
vector< int > ing[N];
int cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      ing[i].clear();
      int m;
      scanf("%d", &m);
      while (m--) {
        int x;
        scanf("%d", &x);
        ing[i].push_back(x);
        cnt[x]++;
      }
    }
    bool ok = 1;
    for (int i = 1; i <= k; i++) if (cnt[i] == 0) {
      ok = 0;
      break;
    }
    if (!ok) {
      puts("sad");
      continue;
    }
    ok = 0;
    for (int i = 0; i < n; i++) {
      ok = 1;
      for (int v : ing[i]) {
        if (cnt[v] <= 1) {
          ok = 0;
          break;
        }
      }
      if (ok)
        break;
    }
    puts(ok ? "some" : "all");
  }

  return 0;
}