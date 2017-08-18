#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;

vector< pair<int, int> > num[N << 2];
int n, a[N];
vector<int> w[N];

void build(int id = 1, int l = 0, int r = n) {
  num[id].clear();
  if (r-l < 2) {
    num[id].emplace_back(1, a[l]);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  auto le = num[il].begin(), ri = num[ir].begin();
  while (le != num[il].end() || ri != num[ir].end()) {
    if (le == num[il].end())
      num[id].push_back(*ri), ri++;
    else if (ri == num[ir].end())
      num[id].push_back(*le), le++;
    else {
      if (le->second == ri->second) {
        num[id].emplace_back(le->first + ri->first, le->second);
        le++, ri++;
      }
      else if (le->second < ri->second)
        num[id].push_back(*le), le++;
      else
        num[id].push_back(*ri), ri++;
    }
  }
}

void ss(int id = 1, int l = 0, int r = n) {
  sort(num[id].begin(), num[id].end());
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  ss(il, l, mid);
  ss(ir, mid, r);
}
int calc(int l, int r, int z) {
  return lower_bound(w[z].begin(), w[z].end(), r) - lower_bound(w[z].begin(), w[z].end(), l);
}

int get(int x, int y, int z, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return n+2;
  if (x <= l && r <= y) {
    int ans = n+2;
    for (int j = 0; j < min(5, (int)num[id].size()); j++) {
      if (calc(x, y, num[id][j].second) > z)
        ans = min(ans, num[id][j].second);
    }
    return ans;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return min(get(x, y, z, il, l, mid), get(x, y, z, ir, mid, r));
}


int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), w[a[i]].push_back(i);
  build();
  ss();
  while (q--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    l--;
    int ans = get(l, r, (r-l)/k);
    printf("%d\n", ans > n ? -1 : ans);
  }
  return 0;
}
