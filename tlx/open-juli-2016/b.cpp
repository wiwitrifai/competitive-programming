#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long bit[N];
int n;

void upd(int x, int v) {
  for(; x; x -= x & (-x))
    bit[x] += v;
}
long long get(int x) {
  long long ret = 0;
  for(; x <= n; x += x&(-x))
    ret += bit[x];
  return ret;
}
int a[N], last[N];
long long ans[N];
pair<pair<int, int>, int > que[N];

bool cmp(pair<pair<int, int>, int > ll, pair<pair<int, int>, int >  rr) {
  if(ll.first.second != rr.first.second)
    return ll.first.second < rr.first.second;
  return ll.first.first < rr.first.first;
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  for(int i = 0; i< n; i++) {
    scanf("%d", a+i);
  }
  for(int i = 0; i<q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--; r--;
    que[i] = {{l, r}, i};
  }
  memset(last, -1, sizeof last);
  sort(que, que+q, cmp);
  int now = 0, prev = 0, noq = 0;
  for(int i = 0; i<n; i++) {
    int bef = last[a[i]];
    while(now <= bef) {
      upd(now+1, i-now);
      now++;
    }
    last[a[i]] = i;
    while(noq < q && que[noq].first.second == i) {
      int id = que[noq].second;
      if(que[noq].first.first >= now) {
        int nn = i-que[noq].first.first+1;
        ans[id] = 1LL*nn*(nn + 1)/2;
      }
      else {
        int nn = i-now+1;
        ans[id] = 1LL*nn*(nn+1)/2 + get(que[noq].first.first+1);
      }
      noq++;
    }
  }
  for(int i = 0; i<q; i++)
    printf("%lld\n", ans[i]);
  return 0;
}