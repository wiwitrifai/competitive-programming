#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
char s[50];
int grund[(1 << 16) + 10];
int a[N];
int bit[N], n;
void upd(int x, int v) {
  for (; x <= n; x+=x&-x) bit[x] ^= v;
}
int get(int x) {
  int ret = 0;
  for (; x; x-=x&(-x)) ret ^= bit[x];
  return ret;
}

int main() {
  vector< int > recmask;
  for (int i = 0; i < 4; i++) {
    for (int j = i+1; j < 5; j++) {
      for (int x = 0; x < 4; x++) {
        for (int y = x+1; y < 5; y++) {
          int now = 0;
          for (int u = i; u < j; u++) {
            for (int v = x; v  < y; v++) {
              now |= (1<< (u * 4 + v));
            }
          }
          recmask.push_back(now);
        }
      }
    }
  }
  int allmask = 1<<16;
  for (int mask = 0; mask < allmask; mask++) {
    set< int > st;
    st.clear();
    for (int v : recmask)
      if ((v & mask) == v) {
        assert((mask ^ v) <  mask);
        st.insert(grund[mask ^ v]);
      }
    grund[mask] = 0;
    for (int v : st) {
      grund[mask] += (grund[mask] == v);
    }
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
      bit[i] = 0;
    for (int i = 0; i < n; i++) {
      int mask = 0;
      for (int x= 0; x < 4; x++) {
        scanf("%s", s);
        for (int y = 0; y < 4; y++)
          if (s[y] == '1')
            mask |= (1<<(x * 4 + y));
      }
      a[i] = grund[mask];
      upd(i+1, a[i]);
    }
    while (m--) {
      int ty;
      scanf("%d", &ty);
      if (ty == 1) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = get(l-1) ^ get(r);
        puts(ans ? "Pishty" : "Lotsy");
      }
      else {
        int pos, mask = 0;
        scanf("%d", &pos);
        for (int i = 0; i < 4; i++) {
          scanf("%s", s);
          for (int j = 0; j < 4; j++)
            if (s[j] == '1')
              mask |= (1<< (i * 4 + j));
        }
        upd(pos, a[pos-1] ^ grund[mask]);
        a[pos-1] = grund[mask];
      }
    }
  }
  return 0;
}