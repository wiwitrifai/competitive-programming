#include <bits/stdc++.h>

using namespace std;

int a, b, c, m;
struct Chip {
  int v[3];
  Chip(int x = 0, int y = 0, int z = 0) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
  }
  bool operator<(Chip ch) const {
    for (int i = 0; i < 3; ++i)
      if (v[i] != ch.v[i])
        return v[i] < ch.v[i];
    return false;
  }
  bool operator==(Chip ch) const {
    for (int i = 0; i < 3; ++i)
      if (v[i] != ch.v[i])
        return false;
    return true;
  }
};
struct Rect {
  int l[3], r[3];
  Rect(int x = 0, int y = 0, int z = 0, int u = 0, int v = 0, int w = 0) {
    l[0] = x, l[1] = y, l[2] = z;
    r[0] = u, r[1] = v, r[2] = w;
  }
  bool inside(Chip & ch) {
    for (int i = 0; i < 3; ++i) {
      if (ch.v[i] < l[i] || ch.v[i] > r[i])
        return false;
    }
    return true;
  }
};
struct Bidang {
  int z, xl, yl, xr, yr, d;
  Bidang (int z = 0, int xl = 0, int yl = 0, int xr = 0, int yr = 0, int d = 0) : z(z), xl(xl), yl(yl), xr(xr), yr(yr), d(d){
  }
  bool operator<(Bidang bid) const {
    return z < bid.z;
  }
  bool operator==(Bidang bid) const {
    return z == bid.z;
  }
};
vector<Chip> chips;
vector<Rect> rect;

ostream& operator<<(ostream& os, Chip ch) {
  return os << "("<<ch.v[0] <<","<<ch.v[1]<<","<<ch.v[2]<<")";
}
ostream& operator<<(ostream& os, Rect ch) {
  return os << "("<<ch.l[0] <<","<<ch.l[1]<<","<<ch.l[2]<<")"<< "("<<ch.r[0] <<","<<ch.r[1]<<","<<ch.r[2]<<")";
}

const int N = 5050;

int bit[N][N];

void upd(int px, int py, int v) {
  for (int x = px; x < N; x += x&-x) {
    for (int y = py; y < N; y += y&-y)
      bit[x][y] += v;
  }
}
int get_bit(int px, int py) {
  int calc = 0;
  for (int x = px; x; x -= x&-x) {
    for (int y = py; y; y -= y&-y)
      calc += bit[x][y];
  }
  return calc;
}

int main() {
  scanf("%d", &a);
  while (a != -1) {
    scanf("%d %d %d", &b, &c, &m);
    Rect all(1,1,1,a,b,c);
    chips.resize(m);
    for (int i = 0; i < m; ++i) {
      Chip ch;
      for (int j = 0; j < 3; ++j)
        scanf("%d", ch.v+j);
      chips[i] = ch;
    }
    rect.resize(m);
    bool ans = true;
    for (int i = 0; i < m; ++i) {
      Rect r;
      for (int j = 0; j < 3; ++j)
        scanf("%d", r.l+j);
      for (int j = 0; j < 3; ++j) {
        scanf("%d", r.r+j);
        if (r.l[j] > r.r[j]) {
          ans = false;
        }
      }
      ans &= r.inside(chips[i]);
      rect[i] = r;
    }
    for (Rect & rec : rect) {
      Chip cl(rec.l[0], rec.l[1], rec.l[2]);
      Chip cr(rec.r[0], rec.r[1], rec.r[2]);
      if (!all.inside(cl) || !all.inside(cr)) {
        ans = false;
        break;
      }
    }
    if (ans) {
      for (Rect & r : rect) {
        for (int mask = 0; mask < 8; ++mask) {
          Chip ch;
          for (int j = 0; j < 3; ++j) {
            ch.v[j] = (mask & (1 << j)) ? r.r[j] : r.l[j];
          }
          int x = ch.v[0], y = ch.v[1], z = ch.v[2];
          chips.emplace_back(Chip(x, y, z));
          chips.emplace_back(Chip(x+1, y, z));
          chips.emplace_back(Chip(x-1, y, z));
          chips.emplace_back(Chip(x, y+1, z));
          chips.emplace_back(Chip(x, y-1, z));
          chips.emplace_back(Chip(x, y, z+1));
          chips.emplace_back(Chip(x, y, z-1));
        }
      }
      chips.emplace_back(Chip(1, 1, 1));
      chips.emplace_back(Chip(a, 1, 1));
      chips.emplace_back(Chip(1, b, 1));
      chips.emplace_back(Chip(1, 1, c));
      chips.emplace_back(Chip(a, b, 1));
      chips.emplace_back(Chip(1, b, c));
      chips.emplace_back(Chip(a, 1, c));
      chips.emplace_back(Chip(a, b, c));
      sort(chips.begin(), chips.end());
      chips.erase(unique(chips.begin(), chips.end()), chips.end());
      vector<int> vx, vy;
      for (Chip & ch : chips) {
        vx.push_back(ch.v[1]);
        vy.push_back(ch.v[2]);
      }
      sort(vx.begin(), vx.end());
      vx.erase(unique(vx.begin(), vx.end()), vx.end());
      sort(vy.begin(), vy.end());
      vy.erase(unique(vy.begin(), vy.end()), vy.end());
      assert(vx.size() + 5 < N && vy.size() + 5 < N);
      auto get_x = [&](int x) {
        return lower_bound(vx.begin(), vx.end(), x) - vx.begin() + 1;
      };
      auto get_y = [&](int y) {
        return lower_bound(vy.begin(), vy.end(), y) - vy.begin() + 1;
      };
      vector<Bidang> events;
      for (Rect & re : rect) {
        events.push_back(Bidang(re.l[0], re.l[1], re.l[2], re.r[1], re.r[2], 1));
        events.push_back(Bidang(re.r[0]+1, re.l[1], re.l[2], re.r[1], re.r[2], -1));
      }
      sort(events.begin(), events.end());
      int it = 0;
      for (auto & ch : chips) {
        if (!all.inside(ch)) continue;
        while (it < (int)events.size() && events[it].z <= ch.v[0]) {
          auto & cur = events[it++];
          cur.xl = get_x(cur.xl);
          cur.xr = get_x(cur.xr);
          cur.yl = get_y(cur.yl);
          cur.yr = get_y(cur.yr);
          upd(cur.xl, cur.yl, cur.d);
          upd(cur.xr+1, cur.yl, -cur.d);
          upd(cur.xl, cur.yr+1, -cur.d);
          upd(cur.xr+1, cur.yr+1, cur.d);
        }
        int x = get_x(ch.v[1]), y = get_y(ch.v[2]);
        int cnt = get_bit(x, y);
        if (cnt != 1) {
          ans = 0;
          break;
        }
      }
      while (it > 0) {
        auto & cur = events[--it];
        upd(cur.xl, cur.yl, -cur.d);
        upd(cur.xr+1, cur.yl, cur.d);
        upd(cur.xl, cur.yr+1, cur.d);
        upd(cur.xr+1, cur.yr+1, -cur.d);
      }
    }
    puts(ans ? "YES" : "NO");
    scanf("%d", &a);
  }
  return 0;
}
