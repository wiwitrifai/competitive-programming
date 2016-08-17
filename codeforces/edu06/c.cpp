#include <bits/stdc++.h>


using namespace std;

const int N = 1e6 + 6;

int a[N], b[N], last[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    b[i] = a[i];
  }
  sort(b, b+n);
  int m = unique(b, b+n) - b;
  memset(last, -1, sizeof last);
  bool ok = true;
  vector < pair<int, int> > ans;
  int l = 0;
  for (int i = 0; i < n; i++) {
    int id = lower_bound(b, b+m, a[i]) - b;
    if (last[id] >= l) {
      ans.push_back(make_pair(l, i));
      l = i+1;
    }
    last[id] = i;
  }
  if (l < n) {
    if (!ans.empty())
      ans[ans.size() - 1].second = n-1;
  }
  if (ans.empty()) {
    puts("-1");
    return 0;
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first+1, ans[i].second+1);
  return 0;
}