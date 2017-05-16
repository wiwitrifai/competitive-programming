#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> a[N];

int ans[N];

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = {x, i};
    tot += (x + 1) / 2;
  }
  if (tot > w) {
    puts("-1");
    return 0;
  }
  sort(a, a+n);
  w -= tot;
  for (int i = n-1; i >= 0; i--) {
    int id = a[i].second;
    ans[id] = (a[i].first + 1)/2;
    a[i].first -= ans[id];
    int c = min(w, a[i].first);
    w -= c;
    ans[id] += c;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}