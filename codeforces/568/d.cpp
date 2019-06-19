#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

pair<int, int> b[N];
bool pre[N], suf[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    b[i] = {x, i};
  }
  sort(b, b+n);
  pre[0] = 1;
  int d = b[1].first - b[0].first;
  for (int i = 1; i < n; ++i) {
    int cur = b[i].first - b[i-1].first;
    if (cur != d) break;
    pre[i] = 1;
  }
  d = b[n-1].first - b[n-2].first;
  suf[n-1] = 1;
  for (int i = n-2; i >= 0; --i) {
    int cur = b[i+1].first - b[i].first;
    if (cur != d) break;
    suf[i] = 1;
  }
  if (pre[n-2]) {
    printf("%d\n", b[n-1].second + 1);
    return 0;
  }
  if (suf[1]) {
    printf("%d\n", b[0].second + 1);
    return 0;
  }
  for (int i = 1; i < n-1; ++i) {
    if (!pre[i-1] || !suf[i+1]) continue;
    if (i+2 < n && (b[i+2].first - b[i+1].first) != (b[i+1].first - b[i-1].first))
      continue;
    if (i-2 >= 0 && (b[i-1].first - b[i-2].first) != (b[i+1].first - b[i-1].first))
      continue;
    printf("%d\n", b[i].second + 1);
    return 0;
  }
  printf("-1\n");
  return 0;
}
