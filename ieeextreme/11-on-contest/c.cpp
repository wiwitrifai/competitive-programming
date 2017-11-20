#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef pair<int, int> point;
#define x first
#define y second

struct fen {
  int bit[N], n;
  fen(int n) : n(n);
  int get(int x) {
    int ret = 0;
    for (; x; x -= x&-x)
      ret += bit[x];
    return ret;
  }

  void upd(int x, int v) {
    for (; x <= n; x += x&-x)
      bit[x] += v;
  }
};

set<pair<point, int> > upper, lower;
vector<pair<point, int> > vp;

int t[N], id[N];
point p[N], q[N];

long long cross(point a, point b, point c) {
  return 1LL * (a.x - b.x) * (c.y - b.y) - 1LL * (a.y - b.y) * (c.x - b.x);
}

bool cekup(point a, point b, point c) {
  return cross(a, b, c) > 0;
}

bool cekdown(point a, point b, point c) {
  return cross(a, b, c) < 0;
}

bool badup(set<pair<point, int> >::iterator it) {
  set<pair<point, int> >::iterator nxt = it, bef = it;
  nxt++;
  if (nxt == upper.end())
    return false;
  if (bef == upper.begin())
    return false;
  bef--;
  return !cekup(*bef, *it, *nxt);
}

bool baddown(set<pair<point, int> >::iterator it) {
  set<pair<point, int> >::iterator nxt = it, bef = it;
  nxt++;
  if (nxt == lower.end())
    return false;
  if (bef == lower.begin())
    return false;
  bef--;
  return !cekdown(*bef, *it, *nxt);
}

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", t+i, &p[i].x, &p[i].y);
    if (t[i]) {
      scanf("%d %d", &q[i].x, &q[i].y);
    }
    else {
      vp.push_back(make_pair(p[i], i));
    }
  }
  sort(vp.begin(), vp.end());
  for (int i = 0; i < vp.size(): i++)
    id[vp[i].second] = i+1;
  fen bup(vp.size() + 2), blow(up.size()+ 2);
  for (int i = 0; i < q; i++) {
    if (t[i] == 0) {
      pair<point, int> now = {p[i], id[i]};
      lower.insert(now);
      set<pair<point, int> >::iterator it = lower.lower_bound(now);
      if (baddown(it))
        lower.erase(it);
      else {
        blow.upd(now.second, +1);
        set<pair<point, int> >::iterator nx = it;
        nx++;
        while (nx != lower.end() && baddown(nx)) {
          blow.upd(nx.second, -1);
          lower.erase(nx++);
        }
        nx = it;
        while (nx != lower.begin()) {
          nx--;
          if (baddown(nx)) {
            blow.upd(nx.second, -1);
            lower.erase(nx);
            nx = it;
          }
          else
            break;
        }
      }

      // upper
      upper.insert(now);
      set<pair<point, int> >::iterator it = upper.lower_bound(now);
      if (badup(it))
        upper.erase(it);
      else {
        bup.upd(now.second, +1);
        set<pair<point, int> >::iterator nx = it;
        nx++;
        while (nx != upper.end() && badup(nx)) {
          bup.upd(nx.second, -1);
          upper.erase(nx++);
        }
        nx = it;
        while (nx != upper.begin()) {
          nx--;
          if (badup(nx)) {
            bup.upd(nx.second, -1);
            upper.erase(nx);
            nx = it;
          }
          else
            break;
        }
      }
    }
    else {
      int ans = 1, tot = upper.size() + lower.size() - 4;
      set<pair<point, int> >::iterator lowa = lower.lower_bound(make_pair(p[i], -1)), lowb = lower.lower_bound(make_pair(q[i], -1));
      set<pair<point, int> >::iterator upa = upper.lower_bound(make_pair(p[i], -1)), upa = upper.lower_bound(make_pair(q[i], -1));
      if (lowa != lower.end() && lowb != lower.end() && lowa->first == p[i] && lowb->first == q[i]) {
        int d = blow.get(lowb->second) - blow.get(lowc->second);
        if (d > 0) {
          d--;
          ans = (tot-d >= d);
        }
        else {
          d = -d - 1;
          ans = (d >= tot-d);
        }
      }
      else if (upa != upper.end() && upb != upper.end() && upa->first == p[i] && upb->first == q[i]) {
        int d = bup.get(lowb->second) - bup.get(lowc->second);
        if (d > 0) {
          d--;
          ans = (d >= tot-d);
        }
        else {
          d = -d - 1;
          ans = (tot-d >= d);
        }
      }
      else if (lowa != lower.end() && upb != upper.end() && lowa->first == p[i] && upb->first == q[i]) {
        int d = blow.get(lowa->second) + bup.get(upb->second) - 3;
        ans = (d >= tot-d);
      }
      else if (upa != upper.end() && lowb != lower.end() && upa->first == p[i] && lowb->first == q[i]) {
        int d = blow.get(lowb->second) + bup.get(upa->second) - 3;
        ans = (tot-d >= d); 
      }
      else {
        cerr << "Ooops!" << endl;
        assert(false);
      }
      puts(ans ? "CW" : "CCW");
    }
  }
  return 0;
}