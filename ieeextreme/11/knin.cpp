#include <bits/stdc++.h>

using namespace std;

const int N = 2505;

int ma[N << 2], lz[N <<2], n;

void build(int id = 1, int l = 0, int r = n) {
  ma[id] = lz[id] = 0;
  if (r - l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void push(int id) {
  if (lz[id] == 0) return;
  int il = id << 1, ir = il | 1;
  ma[il] += lz[id];
  lz[il] += lz[id];
  ma[ir] += lz[id];
  lz[ir] += lz[id];
  lz[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    ma[id] += v;
    lz[id] += v;
    return;
  }
  push(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}

char s[N];
vector<pair<int, int > > vp;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int h, w;
    scanf("%d %d", &h, &w);
    int satu = 0, dua = 0;
    vp.clear();
    int mhw = 2 * max(h, w);
    for (int i = 0; i < h; i++) {
      scanf("%s", s);
      for (int j = 0; j < w; j++) {
        if (s[j] == '.') continue;
        if (s[j] == '1')
          satu++;
        else if (s[j] == '2')
          dua++;
        if (vp.size() <= mhw)
          vp.push_back(make_pair(i, j));
      }
    }
    if (mhw > 2 && vp.size() > mhw)
      puts("NO");
    else if (!(satu == dua || satu == (dua+1)))
      puts("NO");
    else {
      bool ok = 1;
      int mm = min(h, w);
      for (int len = 3; len <= mm && ok; len++) {
        n = w;
        build();
        int le = 0, ri = 0;
        for (int i = 0; i + len <= h && ok; i++) {
          while (ri < vp.size() && vp[ri].first < i + len)
            update(max(0, vp[ri].second-len+1), min(w-len, vp[ri].second) + 1, +1), ri++;
          while (le < ri && vp[le].first < i)
            update(max(0, vp[le].second-len+1), min(w-len, vp[le].second) + 1, -1), le++;
          ok &= ma[1] < len;
        }
      }
      puts(ok ? "YES" : "NO");
    }
  }
  return 0;
}