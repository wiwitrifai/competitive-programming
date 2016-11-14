#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef pair<pair<long long,long long>, int> point;
#define x first.first
#define y first.second
// (p-q) x (r-q)
long long cross(point p, point q, point r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

bool collinear(point a, point o, point b) {
    return cross(a, o, b) == 0;
}

// true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(p, q, r) > 0;
}

point pivot;

long long dist2(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(point a, point b) {
    if(collinear(pivot, a, b)) {
     return dist2(a, pivot) < dist2(b, pivot);
    }
    return ccw(pivot, a, b);
}

bool cmp(point a, point b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}


vector< pair< pair<int, int >, int > > ans;

int main() {
  int n;
  scanf("%d", &n);
  vector< point > vp;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    vp.push_back({{a, b}, i+1}) ;
  }
  int P0 = 0;
  for (int i = 1; i < n; i++)
    if (cmp(vp[i], vp[P0]))
      P0 = i;
  swap(vp[0], vp[P0]);
  pivot = vp[0];
  sort(++vp.begin(), vp.end(), angle_cmp);
  int j = 2;
  point last = {{0, 0}, -1};
  vector< point > st;
  for (int i = 1; i < n; i++) {
    while (st.size() > 1) {
      if (ccw(st[(int)st.size()-2], vp[i], st.back())) {
        ans.push_back({{vp[i].second, st[(int)st.size()-2].second}, st.back().second});
        st.pop_back();
      }
      else
        break;
    }
    if (last.second > 0)
      ans.push_back({{last.second, vp[i].second}, pivot.second});
    st.push_back(vp[i]);
    last = vp[i];
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].second);
  }
  return 0;
}