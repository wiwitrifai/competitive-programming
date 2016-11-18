#include <bits/stdc++.h>

using namespace std;

int bound;
int cnt = 0;
bool cmp(int l, int r) {
  cnt++;
  assert(cnt <= bound);
  printf("? %d %d\n", l, r);
  fflush(stdout);
  char res[10];
  scanf("%s", res);
  return res[0] == '<';
}
void answer(int mi, int ma) {
  printf("! %d %d\n", mi, ma);
  fflush(stdout);
}

pair<int, int> solve(int l, int r) {
  if (l == r)
    return make_pair(l, r);
  if (l + 1 == r) {
    if (cmp(l, r))
      return make_pair(l, r);
    else
      return make_pair(r, l);
  }
  int len = r-l + 1, lenr = len & (-len);
  int mid = len > lenr ? r-lenr : (r+l)/2;
  auto res1 = solve(l, mid), res2 = solve(mid+1, r);
  int ma = cmp(res1.second, res2.second) ? res2.second : res1.second;
  int mi = cmp(res1.first, res2.first) ? res1.first : res2.first;
  return make_pair(mi, ma);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    bound = (3 * n + 1)/2 - 2;
    cnt = 0;
    pair< int, int > ans = solve(1, n);
    answer(ans.first, ans.second);
  }
  return 0;
}