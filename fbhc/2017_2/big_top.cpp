#include <bits/stdc++.h>

using namespace std;

int main() {
  time_t start_t = clock();
  cerr << "Precompute done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl; 
  cerr << "START!" << endl;
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    set< pair< long long, long long > > st;
    int n;
    scanf("%d", &n);
    long long x, ax, bx, cx, h, ah, bh, ch;
    scanf("%lld %lld %lld %lld", &x, &ax, &bx, &cx);
    scanf("%lld %lld %lld %lld", &h, &ah, &bh, &ch);
    double ans = 0;
    double area = 0;
    for (int i = 0; i < n; i++) {
      long long xx = x - h, hh = x + h;
      auto it = st.lower_bound(make_pair(xx, -1));
      long long now = xx, hlast = now;
      if (it != st.end() && it->first == xx) {
        hlast = it->second;
      }
      if (it != st.begin()) {
        auto prev = it;
        prev--;
        if (prev->second >= hlast)
          hlast = prev->second;
      }
      if (hlast >= hh) {
        x = ((ax * x + bx) % cx) + 1;
        h = ((ah * h + bh) % ch) + 1;
        ans += area/2;
        continue;
      }
      while (it != st.end()) {
        if (it->first < hh && it->second < hh) {
          area += (double)(it->first - now) * ((hh-hlast)+(hh-max(it->first, hlast)))/2;
           // cerr << it->first << " " << now << " " << hh << " " << hlast << " | " << endl;
          hlast = it->second;
          now = it->first;
          auto del = it;
          it++;
          st.erase(del);
        }
        else
          break;
      }
       // cerr << area << endl;
      if (it == st.end() || it->first > hh) {
        area += (double)(hh - now) * (hh-hlast)/2;
        // cerr << hh << " " << now << " " << hlast << " " << (hh - now) * (hh-hlast)/2 << endl;
        st.insert(make_pair(hh, hh));
      }
      else {
        area += (double)(it->first - now) * ((hh-hlast)+(hh-max(it->first, hlast)))/2;
      }
      // cerr << x << " " << h << " " << area << endl;
      ans += area/2;
      st.insert(make_pair(xx, hh));
      x = ((ax * x + bx) % cx) + 1;
      h = ((ah * h + bh) % ch) + 1;
    }
    printf("Case #%d: %.9lf\n", tc, ans);
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}