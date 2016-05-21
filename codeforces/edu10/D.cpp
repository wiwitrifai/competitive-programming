#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

pair< pair< int, int> , int > p[N];
int n, a[N], ans[N], m;

int bit[N];
int get(int x) {
  int ret = 0;
  for(x++; x; x-=x&(-x))
    ret += bit[x];
  return ret;
}
void add(int x, int val) {
  for(x++; x <=m; x+= x&(-x))
    bit[x] += val;
} 

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = make_pair(make_pair(x, y), i);
    a[i] = y;
  }
  sort(p, p+n);
  sort(a, a+n);
  m = unique(a, a+n) - a;
  for(int i = n-1; i>=0; i--) {
    int idx = lower_bound(a, a+m, p[i].first.second) - a;
    ans[p[i].second] = get(idx);
    add(idx, 1);
  }
  for(int i = 0; i<n; i++)
    printf("%d\n", ans[i]);
  return 0;
}