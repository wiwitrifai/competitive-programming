#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int c[N], h[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", h+i);
  }
  if (n == 1) {
    printf("%d\n", h[0]);
    return 0;
  }
  vector< pair< int,int > > range;
  int last = h[0];
  int dir = h[1] > h[0] ? 1 : -1;
  for (int i = 1; i < n; i++) {
    int d = h[i] > h[i-1] ? 1 : -1;
    if (d != dir) {
      if (last > h[i-1])
        range.emplace_back(h[i-1], last);
      else
        range.emplace_back(last, h[i-1]);
      dir = d;
      last = h[i-1];
    }
  }
  if (last > h[n-1])
    range.emplace_back(h[n-1], last);
  else
    range.emplace_back(last, h[n-1]);
  vector< int > v;
  for (auto it : range) {
    v.push_back(2 * it.first - 1);
    v.push_back(2 * it.first);
    v.push_back(2 * it.first + 1);
    v.push_back(2 * it.second - 1);
    v.push_back(2 * it.second);
    v.push_back(2 * it.second + 1);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (auto it : range) {
    int id = lower_bound(v.begin(), v.end(), 2 * it.first) - v.begin();
    c[id]++;
    id = lower_bound(v.begin(), v.end(), 2 * it.second) - v.begin();
    c[id]--;
  }
  int now = 0, best = -1;
  for (int i = 0; i < v.size(); i++) {
    if (now >= best) {
      best = now;
    }
    now += c[i];
    if (now >= best) {
      best = now;
    }
  } 
  printf("%d\n", best);
  return 0;
}