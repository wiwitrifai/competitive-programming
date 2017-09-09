/**
 *  ACM ICPC Regional Jakarta 2016 - F : The Cure
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 256, Q = 3e5 + 5, A = 1e4 + 5;;

int bit[N][N], n, q;

void upd(int xx, int yy, int v) {
  for (int x = xx; x <= n; x += x&-x)
    for (int y = yy; y <= n; y += y&-y)
      bit[x][y] += v; 
}

int getb(int xx, int yy) {
  int ret = 0;
  for (int x = xx; x; x -= x&-x)
    for (int y = yy; y; y -= y&-y)
      ret += bit[x][y];
  return ret; 
}

int l[Q], r[Q];
vector<pair<int,int> > pos[A];
vector<int> que[A];
int a[Q], b[Q], s[Q], k[Q];

int main() {
  scanf("%d", &n);
  int ma = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      pos[x].emplace_back(i, j);
      ma = max(ma, x);
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d %d", a+i, b+i, s+i, k+i);
    a[i]--; b[i]--;
    l[i] = 0, r[i] = ma;
    que[(l[i] + r[i]) / 2].push_back(i);
  }
  bool done = 0;
  while (!done) {
    done = 1;
    memset(bit, 0, sizeof bit);
    for (int i = 0; i <= ma; i++) {
      for (auto it : pos[i])
        upd(it.first, it.second, +1);
      for (int id : que[i]) {
        int cnt = getb(a[id]+s[id], b[id]+s[id]) - getb(a[id]+s[id], b[id]) - getb(a[id], b[id]+s[id]) + getb(a[id], b[id]);
        if (cnt < k[id])
          l[id] = i + 1;
        else
          r[id] = i;
        if (l[id] < r[id]) {
          que[(l[id] + r[id])/2].push_back(id);
          done = 0;
        }
      }
      que[i].clear();
    }
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", l[i]);
  return 0;
}