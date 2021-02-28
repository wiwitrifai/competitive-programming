#include <bits/stdc++.h>

using namespace std;

vector<int> c;
int ask(int l, int r, int x) {
#ifdef LOCAL
  int w = 0;
  for (int i = l; i < r; ++i)
    w += c[i];
  return w * c[x];
#endif
  printf("? %d %d\n", r-l, 1);
  for (int i = l; i < r; ++i) {
    printf("%d%c", i+1, i+1 == r ? '\n' : ' ');
  }
  printf("%d\n", x+1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

void answer(vector<int> ans) {
#ifdef LOCAL
  for (int x : ans) {
    cerr << " ans : " << x << endl;
    assert(c[x] == 0);
    c[x] = 1;
  }
  cerr << " done " << endl;
  for (int i = 0; i < (int)c.size(); ++i) {
    assert(c[i] != 0);
  }
#endif
  printf("! %d", (int)ans.size());
  for (int x : ans)
    printf(" %d", x+1);
  printf("\n");
  fflush(stdout);
}

void solve() {
  int n;
  scanf("%d", &n);
#ifdef LOCAL
  c.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[i]);
#endif
  int r = 1;
  while (ask(0, r, r) == 0) ++r;
  int lef = 0, hig = r-1;
  vector<int> flag(n, 0);
  flag[r] = 1;
  while (lef < hig) {
    int mid = (lef + hig) >> 1;
    int res = ask(0, mid+1, r);
    if (res == 0)
      lef = mid + 1;
    else
      hig = mid;
  }
  flag[lef] = 1;
  for (int i = r+1; i < n; ++i)
    flag[i] = ask(i, i+1, r) != 0;
  vector<int> ans;
  for (int i = 0; i < n; ++i)
    if (!flag[i])
      ans.push_back(i);
  answer(ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
