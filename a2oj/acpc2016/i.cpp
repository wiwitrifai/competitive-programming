#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

pair< pair< int, int>, int > p[N];
int vy[N], m, k;
int cnt[N][105], dif[N], mid;

bool add(int y, int z) {
  for (int i = 0; i < m; i++) if (vy[i] <= y && y <= vy[i]+mid) {
    cnt[i][z]++;
    if (cnt[i][z] == 1) {
      dif[i]++;
      if (dif[i] == k)
        return true;
    }
  }
  return false;
}
void del(int y, int z) {
  for (int i = 0; i < m; i++) if (vy[i] <= y && y <= vy[i]+mid) {
    cnt[i][z]--;
    if (cnt[i][z] == 0)
      dif[i]--;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      p[i] = make_pair(make_pair(x, y), z);
      vy[i] = y;
    }
    sort(vy, vy+n);
    m = unique(vy, vy+n) - vy;
    sort(p, p+n);

    int l = 1, r = 2e8 + 5;
    while (l < r) {
      memset(cnt, 0, sizeof cnt);
      memset(dif, 0, sizeof dif);
      int id = 0;
      mid = (l + r) >> 1;
      bool ok = false;
      for (int i = 0; i < n; i++) {
        int x = p[i].first.first, y = p[i].first.second, z = p[i].second;
        while (id < i && x - p[id].first.first > mid) {
          del(p[id].first.second, p[id].second);
          id++;
        }
        if (add(y, z)) {
          ok = true;
          break;
        }
      }
      if (ok)
        r = mid;
      else
        l = mid+1;
    }
    printf("%d\n", l);
  }
  return 0;
}