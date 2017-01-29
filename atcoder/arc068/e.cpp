#include <bits/stdc++.h>
 
using namespace std;
const int M = 1e5 + 6;
vector< int > f[M];
int bit[M];
void upd(int x, int v) {
  for (; x; x -= x&(-x))
    bit[x] += v;
}
int get(int x) {
  int ret = 0;
  for (; x < M; x += x&(-x))
    ret += bit[x];
  return ret;
}
int ans[M];
 
int main() {
  for (int i = 1; i < M; i++) {
    for (int j = i; j < M; j += i)
      f[j].push_back(i);
  }
  int n, m;
  vector< pair< int, int > > ev;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    ev.push_back(make_pair(l, l));
    ev.push_back(make_pair(r+1, -l));
  }
  sort(ev.begin(), ev.end());
  int id = 0;
  for (int i = 1; i <= m; i++) {
    while (id < ev.size() && ev[id].first == i) {
      if (ev[id].second > 0)
        upd(ev[id].second, +1);
      else
        upd(-ev[id].second, -1);
      id++;
    }
    for (int ff : f[i]) {
      ans[ff] += get(i-ff+1);
    }
  }
  for (int i = 1; i <= m; i++)
    printf("%d\n", ans[i]);
  return 0;
}