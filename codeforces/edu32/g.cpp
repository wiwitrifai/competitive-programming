#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 4;

struct node {
  int l, r;
  node(int l = 0, int r = 0) : l(l), r(r) {}
} trie[N * 30];
int nodes;

void add(int root, int x) {
  int now = root;
  for (int i = 29; i >= 0; i--) {
    if (x & (1 << i)) {
      if (!trie[now].r) trie[now].r = ++nodes;
      now = trie[now].r;
    }
    else {
      if (!trie[now].l) trie[now].l = ++nodes;
      now = trie[now].l;
    }
  }
}

int get(int root, int x) {
  int now = root;
  int ans = 0;
  for (int i = 29; i >= 0; i--) {
    if (x & (1 << i)) {
      if (trie[now].r) now = trie[now].r;
      else now = trie[now].l, ans |= 1 << i;
    }
    else {
      if (trie[now].l) now = trie[now].l;
      else now = trie[now].r, ans |= 1 << i;
    }
  }
  return ans;
}

int a[N];

long long solve(int l, int r) {
  if (r <= l) return 0;
  int diff = a[l] ^ a[r];
  if (diff == 0) return 0;
  int val = 0;
  for (int i = 29; i >= 0; i--) {
    val = 1 << i;
    if (diff & val) break;
  }
  int pisah = r;
  for (int i = l; i <= r; i++) {
    if (a[i] & val) {
      pisah = i;
      break;
    }
  }
  long long res = 0;
  if (l < pisah-1)
    res += solve(l, pisah-1);
  if (pisah < r)
    res += solve(pisah, r);
  while (nodes > 0) nodes--, trie[nodes].l = trie[nodes].r = 0;
  int root = ++nodes;
  int cur = 1 << 30;
  for (int i = l; i < pisah; i++) {
    add(root, a[i]);
  }
  for (int i = pisah; i <= r; i++)
    cur = min(cur, get(root, a[i]));
  res += cur;
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  cout << solve(0, n-1) << endl;
  return 0;
}