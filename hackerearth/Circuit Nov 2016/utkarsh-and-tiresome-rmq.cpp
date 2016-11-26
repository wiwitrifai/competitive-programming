#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
long long a[N], b;
long long tmp[N], ans[N];

bool cmp(pair< pair<int, int >, int > l, pair< pair<int, int >, int > r) {
  if (l.first.first != r.first.first)
    return l.first.first < r.first.first;
  int vl = l.first.second % l.first.first, vr = r.first.second % r.first.first;
  if (vl != vr)
    return vl < vr;
  return l.first.second < r.first.second;
}

int main() {
  int n, q, m;
  scanf("%d %d %lld %d", &n, &q, &b, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a+i); 
  }
  vector< pair< pair<int, int >, int > > vq;
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d %d", &x, &y); x--;
    vq.push_back({{y, x}, i});
  }
  sort(vq.begin(), vq.end(), cmp);
  int y = 1, x = -1, off = 0;
  deque< int > id;
  for (int i = 0; i < q; i++) {
    if (vq[i].first.first != y || ((x % y) != (vq[i].first.second % vq[i].first.first))) {
      y = vq[i].first.first;
      x = (vq[i].first.second % y) - y;
      off = 0;
      id.clear();
    }
    int tox = vq[i].first.second;
    while (x < tox) {
      x += y;
      tmp[off] = a[x] - b * off;
      while (!id.empty()) {
        if (tmp[id.front()] < tmp[off])
          id.pop_front();
        else
           break;
      }
      id.push_front(off);
      off++;
      while (!id.empty() && id.back() < off - m) id.pop_back();
    }
    ans[vq[i].second] = tmp[id.back()] + b * off;
  }
  for (int i = 0; i < q; i++)
    printf("%lld\n", ans[i]);
  return 0;
}