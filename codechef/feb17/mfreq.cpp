#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector< pair<int, int > > v;
  int last = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    if (a[last] != a[i]) {
      v.emplace_back(last, i);
      last = i;
    }
  }
  v.emplace_back(last, n);
  for (int i = 0; i < m; i++) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    l--;
    int mid = (l+r)/2;
    int id = upper_bound(v.begin(), v.end(), make_pair(mid, n)) - v.begin() - 1;
    if (id < 0 || id >= v.size() || min(v[id].second, r) - max(v[id].first, l) < k)
      puts("-1");
    else
      printf("%d\n", a[mid]);
  }
  return 0;
}