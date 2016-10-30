#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e17;
const int G = sqrt(N);

int n, last[N + N];
struct seg_tree
{
  long long val[N << 2], lazy[N << 2], best[N << 2], blazy[N << 2];
  void build(int id = 1, int l = 0, int r = n) {
    lazy[id] = 0;
    blazy[id] = 0;
    best[id] = 0;
    val[id] = 0;
    if (r-l < 2) {
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
  }
  void shift(int id) {
    if (lazy[id] == 0 && blazy[id] == 0)
      return;
    int il = id << 1, ir = il | 1;
    best[il] = max(best[il], val[il] + blazy[id]);
    blazy[il] = max(blazy[il], lazy[il] + blazy[id]);
    val[il] += lazy[id];
    lazy[il] += lazy[id];
    best[ir] = max(best[ir], val[ir] + blazy[id]);
    blazy[ir] = max(blazy[ir], lazy[ir] + blazy[id]);
    val[ir] += lazy[id];
    lazy[ir] += lazy[id];
    lazy[id] = 0;
    blazy[id] = 0;
  }
  void update2(int x, int y, long long v, int id = 1, int l = 0, int r = n) {
    if (x >= r || y <= l) return;
    if (x <= l && r <= y) {
      val[id] += v;
      lazy[id] += v;
      blazy[id] = max(blazy[id], lazy[id]);
      best[id] = max(best[id], val[id]);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    shift(id);
    update2(x, y, v, il, l, mid);
    update2(x, y, v, ir, mid, r);
    val[id] = max(val[il], val[ir]);
    best[id] = max(best[il], best[ir]);
  }
  long long get(int x, int y, int id = 1, int l = 0, int r = n) {
    if (x >= r || y <= l) return 0;
    if (x <= l && r <= y) {
      // cerr << l << " " << r << " " << best[id] << endl;
      return best[id];
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    shift(id);
    return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  }
};
int a[N];
long long ans[N];

seg_tree rmq;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  int m;
  scanf("%d", &m);
  vector< pair<pair<int, int>, int> > que;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    que.push_back({{x-1, y-1}, i});
  }
  sort(que.begin(), que.end(), [](pair< pair<int, int>, int > a, pair< pair<int, int>, int > b) {
    return a.first.second < b.first.second;
  });
  rmq.build();
  memset(last, 0, sizeof last);
  int j = 0;
  for (int i = 0; i < n; i++) {
    rmq.update2(last[a[i]+N], i+1, a[i]);
    last[a[i]+N] = i+1;
    while (j < que.size()) {
      int l = que[j].first.first, r = que[j].first.second, id = que[j].second;
      if (r == i) {
        ans[id] = rmq.get(l, r+1);
        j++;
      }
      else
        break;
    }
  }
  for (int i = 0; i < m; i++)
    printf("%lld\n", ans[i]);

  return 0;
}