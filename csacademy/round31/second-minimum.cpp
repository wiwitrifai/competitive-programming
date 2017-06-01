#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
  printf("Q %d %d\n", l, r);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans == l;
}
void answer(int x) {
  printf("A %d\n", x);
  fflush(stdout);
}
const int N = 1e4 + 5;
vector< int > ve[N];
int solve(int l, int r)  {
  assert(l <= r);
  if (l == r)
    return l;
  int mid = (l + r)/2;
  int le = solve(l, mid), ri = solve(mid+1, r);
  if (!ask(le, ri))
    swap(le, ri);
  ve[le].push_back(ri);
  return le;
}

int main() {
  int n;
  scanf("%d", &n);
  int mi = solve(1, n);
  sort(ve[mi].begin(), ve[mi].end());
  int ans = ve[mi][0];
  for (int j = 1; j < ve[mi].size(); j++)
    if (ask(ve[mi][j], ans))
      ans = ve[mi][j];
  answer(ans);
  return 0;
}