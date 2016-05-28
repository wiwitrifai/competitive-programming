#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 5;

int a[N<<2], b[N], n;

void build(int id = 1, int l = 0, int r = n) {
  a[id] = 0;
  if(r-l < 2)
    return ;
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
}

int get(int val, int id = 1, int l = 0, int r = n) {
  a[id]--;
  if(r-l < 2)
    return b[l];
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  if(a[il] < val)
    return get(val-a[il], ir, mid, r);
  else
    return get(val, il, l, mid);
}
void upd(int x, int id = 1, int l = 0, int r = n) {
  a[id]++;
  if(r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  if(x >= b[mid])
    upd(x, ir, mid, r);
  else
    upd(x, il, l, mid);
}
int que[N];
char s[1000];

int main() {
  int q = 0;
  while(scanf("%s", s) == 1) {
    if(s[0] =='#')
      que[q] = -1;
    else
      que[q] = atoi(s);
    b[q] = que[q];
    q++;
  }
  sort(b, b+q);
  n = unique(b, b+q) - b;
  build();
  int sz = 0;
  for(int i = 0; i<q; i++) {
    if(que[i] > -1) {
      upd(que[i]);
      sz++;
    }
    else {
      printf("%d\n", get(sz/2 + 1));
      sz--;
    }
  }
  return 0;
}