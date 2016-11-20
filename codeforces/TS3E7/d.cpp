#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ca[N], cb[N];
int a[N], q;
long long ans[N];
int block;

vector< pair< pair<int, int >, int> > que;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int l, r, x, y;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    l--; r--; x--; y--;
    que.push_back({{r, y}, i});
    if (x)
      que.push_back({{r, x-1}, -i});
    if (l)
      que.push_back({{l-1, y}, -i});
    if (x && l)
      que.push_back({{l-1, x-1}, i});
    ans[i] = 0;
  }
  block = sqrt(n)+1;
  sort(que.begin(), que.end(), [](pair<pair<int, int >, int >  a, pair<pair<int, int >, int >  b) {
    int ba = a.first.first/block, bb = b.first.first/block;
    if (ba != bb)
      return ba < bb;
    return a.first.second < b.first.second;
  });
  int l = -1, r = -1;
  long long cur = 0;
  for (auto it : que) {
    int x = it.first.first, y = it.first.second, id = it.second;
    while (l < x) {
      l++;
      ca[a[l]]++;
      cur += cb[a[l]];
    }
    while (l > x) {
      ca[a[l]]--;
      cur -= cb[a[l]];
      l--;
    }
    while (r < y) {
      r++;
      cb[a[r]]++;
      cur += ca[a[r]];
    }
    while (r > y) {
      cb[a[r]]--;
      cur -= ca[a[r]];
      r--;
    }
    if (id < 0)
      ans[-id] -= cur;
    else
      ans[id] += cur;
  }
  for (int i = 1; i <= q; i++)
    printf("%I64d\n", ans[i]);
  return 0;
}