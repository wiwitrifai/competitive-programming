#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long > point;
int ccw(point a, point b, point c) {
  long long bx = b.first - a.first, by = b.second - a.second;
  long long cx = c.first - a.first, cy = c.second - a.second;
  long long cross = bx * cy - by * cx;
  if (cross == 0) return 0;
  return cross > 0 ? 1 : -1;
}

vector<point> process(vector<point> vp) {
  int n = vp.size();
  sort(vp.begin(), vp.end());
  vector<point> upper, lower;
  for (int i = 0; i < n; ++i) {
    int sz;
    while ((sz = upper.size()) >= 2 && ccw(upper[sz-2], upper[sz-1], vp[i]) > 0) upper.pop_back();
    while ((sz = lower.size()) >= 2 && ccw(lower[sz-2], lower[sz-1], vp[i]) < 0) lower.pop_back();
    upper.push_back(vp[i]);
    lower.push_back(vp[i]);
  }
  vector<point> ans;
  int need = n/10;
  for (int x = vp[0].first+1, i = 0, j = 0; x < vp.back().first && ans.size() < need; ++x) {
    while (upper[i+1].first <= x) ++i;
    while (lower[j+1].first <= x) ++j;
    long long ymin = lower[j].second + 1LL * (x - lower[j].first) * (lower[j+1].second - lower[j].second) / (lower[j+1].first - lower[j].first);
    while (ccw(lower[j], lower[j+1], {x, ymin}) > 0) --ymin; 
    while (ccw(lower[j], lower[j+1], {x, ymin}) <= 0) ++ymin; 
    long long ymax = upper[i].second + 1LL * (x - upper[i].first) * (upper[i+1].second - upper[i].second) / (upper[i+1].first - upper[i].first);
    while (ccw(upper[i], upper[i+1], {x, ymax}) < 0) ++ymax; 
    while (ccw(upper[i], upper[i+1], {x, ymax}) >= 0) --ymax; 
    for (int y = ymin; y <= ymax && ans.size() < need; ++y)
      ans.push_back({x, y});
  }
  return ans;
}
vector<point> solve(vector<point> vp) {
  int n = vp.size();
  long long xmin = vp[0].first, xmax = vp[0].first;
  long long ymin = vp[0].second, ymax = vp[0].second;
  for (int i = 0; i < n; ++i) {
    xmin = min(xmin, vp[i].first);
    xmax = max(xmax, vp[i].first);
    ymin = min(ymin, vp[i].second);
    ymax = max(ymax, vp[i].second);
  }
  if (ymax-ymin > xmax-xmin)
    return process(vp);
  for (point & p : vp)
    swap(p.first, p.second);
  vector<point> ans = process(vp);
  for (point & p : ans)
    swap(p.first, p.second);
  return ans;
}
vector<point> vp;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vp.resize(n);
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      vp[i] = {x, y}; 
    }
    int need = n/10;
    vector<point> ans = solve(vp);
    if (ans.size() < need)
      puts("-1");
    else
      for (auto it : ans)
        printf("%d %d\n", (int)it.first, (int)it.second); 
  }
  return 0;
}