#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(int _x = 0, int _y = 0) : x(_x), y(_y) {
  }
  point operator-(point p) {
    return point(x-p.x, y-p.y);  
  }
  point operator+(point p) {
    return point(x + p.x, y + p.y);
  }
  long long operator*(point p) {
    return 1ll * x * p.x + 1ll * y * p.y;
  }
  long long operator%(point p) {
    return 1LL* x * p.y - 1LL * y * p.x;
  }
};

const int N = 3000;
int n;
point pp[N], pivot;
vector< point > up[N], down[N], all[N];

bool cmp(point a, point b) {
  return (a - pivot) % (b - pivot) > 0;
}

int count(int id, point lo, point hi) {
  // cerr << id << " " << lo.x << " " << lo.y << " - " << hi.x << " " << hi.y << endl;
  int ret = 0;
  pivot = pp[id];
  bool lodown = (lo.y < pp[id].y || (lo.y == pp[id].y && lo.x < pp[id].x)),
    hidown = (hi.y < pp[id].y || (hi.y == pp[id].y && hi.x < pp[id].x));

  int l = lodown ? 0 : lower_bound(up[id].begin(), up[id].end(), lo, cmp) - up[id].begin();
  int r;
  if(hidown) {
    r = lodown ? 0 : (int)up[id].size();
  }
  else {
    r = lower_bound(up[id].begin(), up[id].end(), hi, cmp) - up[id].begin();
  }
  ret += r - l;
  // cerr << l << " " <<r << endl;
  l = !lodown ? 0 : lower_bound(down[id].begin(), down[id].end(), lo, cmp) - down[id].begin();
  r;
  if(!hidown) {
    r = !lodown ? 0 : (int)down[id].size();
  }
  else {
    r = lower_bound(down[id].begin(), down[id].end(), hi, cmp) - down[id].begin();
  }
  // cerr << l << " " <<r << endl;
  ret += r - l;
  // cerr << ret << endl;
  return ret;
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    pp[i] = point(x, y);
  }
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) if(i != j) {
      if(pp[i].y < pp[j].y || (pp[i].y == pp[j].y && pp[j].x > pp[i].x))
        up[i].push_back(pp[j]);
      else
        down[i].push_back(pp[j]);
    }
    pivot = pp[i];
    sort(up[i].begin(), up[i].end(), cmp);
    sort(down[i].begin(), down[i].end(), cmp);
    // cerr << i << " " << pp[i].x << " " << pp[i].y << endl;
    // for(int j = 0; j<up[i].size(); j++)
    //   cerr << up[i][j].x << " u " << up[i][j].y << endl;
    // for(int j = 0; j<down[i].size(); j++)
    //   cerr << down[i][j].x << " d " << down[i][j].y << endl;
  }
  long long ans = 0;
  for(int i = 0; i<n; i++)
    for(int j = i+1; j<n; j++) {
      point d = pp[j]-pp[i];
      ans += 1LL * count(i, pp[i]-point(-d.y, d.x), pp[j]) * count(j, pp[j]+point(-d.y, d.x), pp[i]);
    }
  cout << ans << endl;
  return 0;
}