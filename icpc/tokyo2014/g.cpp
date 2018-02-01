#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int sum[N << 2], mi[N << 2], n;
char s[N];
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    sum[id] = s[l] == ')' ? +1 : -1;
    mi[id] = sum[id];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  sum[id] = sum[il] + sum[ir];
  mi[id] = min(mi[il] + sum[ir], mi[ir]);
}
int get(int now = 0, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    return l;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (now + mi[ir] < 0)
    return get(now, ir, mid, r);
  return get(sum[ir]+now, il, l, mid); 
}
void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    sum[id] = mi[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
  mi[id] = min(mi[il] + sum[ir], mi[ir]);
}
set<int> open, close;

void closeBracket(int x) {
  open.erase(x);
  close.insert(x);
  update(x, +1);
  s[x] = ')';
}
void openBracket(int x) {
  close.erase(x);
  open.insert(x);
  update(x, -1);
  s[x] = '(';
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  build();
  for (int i = 0; i < n; ++i)
    if (s[i] == '(')
      open.insert(i);
    else
      close.insert(i);
  while (q--) {
    int x;
    scanf("%d", &x);
    --x;
    int ans;
    if (s[x] == '(') {
      closeBracket(x);
      ans = *close.begin();
      openBracket(ans);
    }
    else {
      openBracket(x);
      ans = get();
      closeBracket(ans);
    }
    printf("%d\n", ans+1);
  }
  return 0;
}