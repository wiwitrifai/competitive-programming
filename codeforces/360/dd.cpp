#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, M = 1e6 + 6;

int p[N], n, m, q, u[M], v[M], w[M], id[M];
bool color[N];
int find(int x) {
  if(p[x] < 0)
    return x;
  int bef = p[x];
  p[x] = find(p[x]);
  color[x] = (color[x] != color[bef]);
  return p[x];
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 0; i<m; i++) {
    scanf("%d%d%d", u+i, v+i, w+i);
    u[i]--; v[i]--;
    id[i] = i;
  }
  sort(id, id+m, [](int x, int y) {
    return w[x] > w[y];
  });
  while(q--) {
    for(int i = 0; i<n; i++) {
      p[i] = -1;
      color[i] = 0;
    }
    int l, r;
    scanf("%d%d", &l, &r); l--; r--;
    int ans = -1;
    for(int i = 0; i<m; i++) {
      if(id[i] < l || id[i] > r)
        continue;
      int x = u[id[i]], y = v[id[i]];
      int px = find(x), py = find(y);
      if(px == py) {
        if(color[x] == color[y]) {
          ans = w[id[i]];
          break;
        }
        else
          continue;
      }
      if(p[px] > p[py])
        swap(px, py);
      p[px] += p[py];
      p[py] = px;
      color[py] = (color[x] == color[y]);
    }
    printf("%d\n", ans);
  }
  return 0;
}