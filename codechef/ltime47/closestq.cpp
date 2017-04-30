#include <bits/stdc++.h>

using namespace std;

const int N = 75050, inf = 1e9 + 7;

typedef pair< int, int > point;
#define x first
#define y second

set< point > st;
map< point, point > mp;
set< point > opt;
int last;

char s[100];
int solve(int ans = inf) {
  if (st.size() < 2) return 0;
  set< point > sv;
  set< pair< point, point > > best;
  mp.clear();
  for (auto it = st.begin(), le = it; it != st.end(); it++) {
    while (it->x - le->x > ans) sv.erase(point(le->y, le->x)), le++;
    auto lo = sv.lower_bound(point(it->y-ans, -inf));
    while (lo != sv.end() && lo->x < it->y+ans) {
      int dx = it->x - lo->y, dy = it->y - lo->x;
      int cur = dx * dx + dy * dy;
      if (cur < ans) {
        best.clear();
        ans = cur;
      }
      if (cur == ans) {
        point b(lo->y, lo->x);
        if (b < *it)
          best.insert(make_pair(b, *it));
        else
          best.insert(make_pair(*it, b));
      }
      lo++;
    }
    sv.insert(point(it->y, it->x));
  }
  for (auto it : best) {
    if (mp.count(it.x) || mp.count(it.y)) continue;
    mp[it.x] = it.y;
    mp[it.y] = it.x;
  }
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  int last = inf;
  while (q-- > 0) {
    int x, y;
    scanf("%s %d %d", s, &x, &y);
    if (last == 0) last = inf;
    if (s[0] == '+') {
      st.insert(point(x, y));
      last = solve(last);
    }
    else {
      point b (x, y);
      st.erase(b); 
      if (mp.count(b)) {
        point a = mp[b];
        mp.erase(a);
        mp.erase(b);
      }
      if (mp.empty()) {
        last = solve();
      }
    }
    if (last == inf) last = 0;
    printf("%d\n", last);
  }
  return 0;
}