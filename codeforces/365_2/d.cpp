#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

struct fen
{
  int n;
  int bit[N];
  fen(int n) : n(n) {
    memset(bit, 0, sizeof bit);
  }
  void upd(int x, int v) {
    for(; x; x-=x&(-x))
      bit[x] ^= v;
  }
  int get(int x) {
    int ret = 0;
    for(; x<=n; x+=x&(-x))
      ret ^= bit[x];
    return ret;
  }
};
int a[N], ans[N];
pair< pair<int, int>, int > que[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  int m;
  scanf("%d", &m);
  for(int i = 0; i<m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    que[i] = {{--r, --l}, i};
  }
  sort(que, que+m);
  fen even(n);
  map< int, int > last;
  int noq = 0;
  for(int i = 0; i<n; i++) {
    if(last.count(a[i]))
      even.upd(last[a[i]], a[i]);
    last[a[i]] = i+1;
    while(noq < m && que[noq].first.first == i) {
      ans[que[noq].second] = even.get(que[noq].first.second+1);
      noq++;
    }
  }
  for(int i = 0; i<m; i++)
    printf("%d\n", ans[i]);
  return 0;
}