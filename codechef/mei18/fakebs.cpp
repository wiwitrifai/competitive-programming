#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], ans[N];
vector<int> val;
int n;

int getId(int x) {
  return lower_bound(val.begin(), val.end(), x) - val.begin();
}

vector<int> cur;
void solve(int l, int r) {
  if (r < l) return;
  int mid = (l + r) >> 1;
  int low = 0, up = 0;
  for (int i = 0; i < cur.size(); ++i)
    if (cur[i] < 0)
      ++low;
    else
      ++up;
  if (a[mid]-1 < low || (n-a[mid]) < up)
    ans[a[mid]] = -1;
  else {
    int cntl = 0, cnth = 0;
    for (int i = 0; i < cur.size(); ++i) {
      if (cur[i] < 0)
        cntl += -cur[i] > a[mid];
      else
        cnth += cur[i] < a[mid];
    }
    ans[a[mid]] = max(cntl, cnth);
  }
  cur.push_back(a[mid]);
  solve(l, mid-1);
  cur.back() *= -1;
  solve(mid+1, r);
  cur.pop_back();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d %d", &n, &q);
    val.resize(n+1);
    val[n] = 0;
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i), val[i] = a[i];
    sort(val.begin(), val.end());
    for (int i = 0; i < n; ++i)
      a[i] = getId(a[i]);
    solve(0, n-1);
    while (q--) {
      int x;
      scanf("%d", &x);
      printf("%d\n", ans[getId(x)]);
    }
  }
  return 0;
}