#include <bits/stdc++.h>

using namespace std;

void answer(int v) {
  printf("! %d\n", v);
  fflush(stdout);
  exit(0);
}

vector<int> ask(int l, int r) {
  printf("? %d", r-l+1);
  for (int i = l; i <= r; ++i)
    printf(" %d", i);
  printf("\n");
  fflush(stdout);
  int n;
  scanf("%d", &n);
  vector<int> ret(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &ret[i]);
  return ret;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<int> res = ask(1, n+m);
  if ((int)res.size() != n + m) {
    sort(res.begin(), res.end());
    int ans = 1;
    for (int x : res) {
      if (ans == x)
        ++ans;
      else
        break;
    }
    answer(ans);
    return 0;
  }
  int lo = 1, hi = n + m;
  if (n < m)
    hi = n;
  else
    lo = n+1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if ((int)ask(lo, mid).size() > mid - lo + 1)
      hi = mid;
    else
      lo = mid + 1;
  }
  answer(lo);
  return 0;
}
