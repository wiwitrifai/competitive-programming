#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 0x7FFFFFFFFFFFFFFFLL;

int n;
long long x[N], y[N], z[N];

long long div2(long long v) {
  return v < 0 ? (v-1)/2 : v/2;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
      scanf("%I64d%I64d%I64d", x+i, y+i, z+i);
    long long l = 0, r = 3e18+10;
    while(l < r) {
      long long mid = l + (r-l)/2;
      pair<long long, long long> s, a, b, c;
      s = a = b = c = make_pair(-inf, inf);
      bool ok = true;
      for(int i = 0; i<n; i++) {
        long long cur = x[i] + y[i] + z[i];
        // if(cur < 0) cur = -cur;
        s.first = max(s.first, cur - mid);
        s.second = min(s.second, cur + mid);
        cur = -x[i] + y[i] + z[i];
        // if(cur < 0) cur = -cur;
        a.first = max(a.first, cur - mid);
        a.second = min(a.second, cur + mid);
        cur = x[i] - y[i] + z[i];
        // if(cur < 0) cur = -cur;
        b.first = max(b.first, cur - mid);
        b.second = min(b.second, cur + mid);
        cur = x[i] + y[i] - z[i];
        // if(cur < 0) cur = -cur;
        c.first = max(c.first, cur - mid);
        c.second = min(c.second, cur + mid);
      }
      if(s.first > s.second || a.first > a.second || b.first > b.second || c.first > c.second)
        ok = false;
      if((a.first + b.first + c.first) > s.second || (a.second + b.second + c.second) < s.first)
        ok = false;
      ok = false;
      for(int i = 0; i<2; i++) {
        pair<long long, long long> ss, aa, bb, cc;
        ss = make_pair((s.first - i + 1)/2, (s.second-i)/2);
        aa = make_pair((a.first - i + 1)/2, (a.second-i)/2);
        bb = make_pair((b.first - i + 1)/2, (b.second-i)/2);
        cc = make_pair((c.first - i + 1)/2, (c.second-i)/2);
        if(ss.first <= ss.second &&  aa.first <= aa.second && bb.first <= bb.second && cc.first <= cc.second && (aa.first + bb.first + cc.first + i) <= ss.second || (aa.second + bb.second + cc.second + i) >= ss.first) {
          ok = true;
          break;
        }
      }
      if(ok)
        r = mid;
      else
        l = mid + 1;
    }
    pair<long long, long long> s, a, b, c;
    s = a = b = c = make_pair(-inf, inf);
    long long mid = l; 
    for(int i = 0; i<n; i++) {
      long long cur = x[i] + y[i] + z[i];
      // if(cur < 0) cur = -cur;
      s.first = max(s.first, cur - mid);
      s.second = min(s.second, cur + mid);
      cur = -x[i] + y[i] + z[i];
      // if(cur < 0) cur = -cur;
      a.first = max(a.first, cur - mid);
      a.second = min(a.second, cur + mid);
      cur = x[i] - y[i] + z[i];
      // if(cur < 0) cur = -cur;
      b.first = max(b.first, cur - mid);
      b.second = min(b.second, cur + mid);
      cur = x[i] + y[i] - z[i];
      // if(cur < 0) cur = -cur;
      c.first = max(c.first, cur - mid);
      c.second = min(c.second, cur + mid);
    }
    // cerr << l << endl;
    // cerr << s.first << " " << s.second << endl;
    // cerr << a.first << " " << a.second << endl;
    // cerr << b.first << " " << b.second << endl;
    // cerr << c.first << " " << c.second << endl;
    pair<long long, long long> ss, aa, bb, cc;
    long long p, q, rr;
    for(int i = 0; i<2; i++) {
      ss = make_pair(div2(s.first - i + 1), div2(s.second-i));
      aa = make_pair(div2(a.first - i + 1), div2(a.second-i));
      bb = make_pair(div2(b.first - i + 1), div2(b.second-i));
      cc = make_pair(div2(c.first - i + 1), div2(c.second-i));
      if(ss.first <= ss.second &&  aa.first <= aa.second && bb.first <= bb.second && cc.first <= cc.second && (aa.first + bb.first + cc.first + i) <= ss.second && (aa.second + bb.second + cc.second + i) >= ss.first) {
        long long delta = max(0LL, ss.first-aa.first-bb.first-cc.first-i);
        long long add = min(delta, aa.second - aa.first);
        aa.first = (aa.first + add);
        delta -= add;
        add = min(delta, bb.second - bb.first);
        bb.first = (bb.first + add);
        delta -= add;
        add = min(delta, cc.second - cc.first);
        cc.first = (cc.first + add);
        delta -= add;
        p = bb.first + cc.first + i;
        q = aa.first + cc.first + i;
        rr = bb.first + aa.first + i;
        assert(delta == 0);
        // cerr << "ok\n";
        break;
      }
    }

    printf("%I64d %I64d %I64d\n", p, q, rr);
  }
  return 0;
}