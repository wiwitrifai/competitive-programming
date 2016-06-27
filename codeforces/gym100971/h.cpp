#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int bit[N], n;

int get(int x) {
  int ret = 0;
  for(;x; x -= x&(-x))
    ret += bit[x];
  return ret;
}
int upd(int x, int val) {
  for(; x<= n+1; x += x &(-x))
    bit[x] += val;
}

queue< int > que[N];
int lo[N], hi[N], a[N], b[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i<=n; i++)
    scanf("%d%d", a+i, b+i);
  for(int i = 1; i<=n; i++) {
    lo[i] = 1;
    hi[i] = n+1;
    que[(n+2)/2].push(i);
  }
  bool change = true;
  while(change) {
    change = false;
    for(int i = 1; i<=n+1; i++)
      bit[i] = 0;
    for(int i = 1; i<=n; i++) {
      upd(a[i], 1);
      upd(b[i]+1, -1);
      while(!que[i].empty()) {
        int now = que[i].front(); que[i].pop();
        if(get(now) >= now)
          hi[now] = i;
        else
          lo[now] = i+1;
        if(lo[now] < hi[now]) {
          change = true;
          que[(lo[now]+hi[now])>>1].push(now);
        }
      }
    }
  }
  for(int i = 1; i<=n; i++) {
    printf("%d ", lo[i] <= n ? lo[i] : -1);
  }
  printf("\n");
  
  return 0;
}