#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int s[N][N];
int ans[N];

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", s[i]+j);
    }
  }
  vector<pair<int, int> > cat, mouse;
  for (int i = 0; i < p; ++i) {
    char c; int x;
    scanf(" %c %d", &c, &x);
    if (c == 'C') x += n;
    cat.emplace_back(x, i);
  }
  for (int i = 0; i < p; ++i) {
    char c; int x;
    scanf(" %c %d", &c, &x);
    if (c == 'R') x += n;
    mouse.emplace_back(x, i);
  }
  sort(cat.begin(), cat.end());
  sort(mouse.begin(), mouse.end());
  for (int i = 0; i < p; ++i)
    ans[cat[i].second] = mouse[i].second;
  for (int i = 0; i < p; ++i)
    printf("%d\n", ans[i]+1);
  return 0;
}