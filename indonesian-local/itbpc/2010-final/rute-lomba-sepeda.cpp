#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

pair<int, int> p[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, h;
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      p[i] = {y, x};
    }
    sort(p, p+n);
    deque<int> hi, lo;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      while (j < i && p[i].first - p[j].first > h) {
        if (!hi.empty() && hi.front() == p[j].second)
          hi.pop_front();
        if (!lo.empty() && lo.front() == p[j].second)
          lo.pop_front();
        j++;
      }
      while (!hi.empty() && hi.back() < p[i].second) hi.pop_back();
      while (!lo.empty() && lo.back() > p[i].second) lo.pop_back();
      hi.push_back(p[i].second);
      lo.push_back(p[i].second);
      ans = max(ans, max(hi.front() - p[i].second, p[i].second - lo.front()));
    }
    printf("%d\n", ans);
  }
  return 0;
}