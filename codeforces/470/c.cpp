#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
struct trie {
  int l, r, cnt;
  trie() : l(0), r(0), cnt(0) {}
} node[N * 55];

int p[N], a[N], cntr;
void add(int x) {
  int now = 1;
  ++node[now].cnt;
  for (int i = 29; i >= 0; --i) {
    if (x & (1 << i)) {
      if (node[now].r == 0) node[now].r = cntr++;
      now = node[now].r;
    }
    else {
      if (node[now].l == 0) node[now].l = cntr++;
      now = node[now].l;
    }
    ++node[now].cnt;
  }
}

void remove(int x) {
  int now = 1;
  --node[now].cnt;
  for (int i = 29; i >= 0; --i) {
    if (x & (1 << i))
      now = node[now].r;
    else
      now = node[now].l;
    if (!now) break;
    --node[now].cnt;
  }
}

int get(int x) {
  int now = 1, ret = 0;
  for (int i = 29; i >= 0; --i) {
    int il = node[now].l, ir = node[now].r;
    if ((x & (1 << i)) == 0) {
      if (il > 0 && node[il].cnt > 0) {
        now = il;
      }
      else {
        ret |= (1 << i);
        now = ir;
      }
    }
    else {
      if (ir > 0 && node[ir].cnt > 0) {
        now = ir;
      }
      else {
        ret |= (1 << i);
        now = il;
      }
    }
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  cntr = 2;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i), add(p[i]);
  }
  for (int i = 0; i < n; ++i) {
    int ans = get(a[i]);
    remove(ans^a[i]);
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}