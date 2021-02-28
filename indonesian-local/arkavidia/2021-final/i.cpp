#include <bits/stdc++.h>

using namespace std;

struct BIT {
  vector<long long> bit;

  BIT(int _n) : bit(_n+1, 0) {}

  long long get(int x) {
    long long ret = 0;
    for (++x; x; x -= x&-x)
      ret += bit[x];
    return ret;
  }

  void upd(int x, long long v) {
    for (++x; x < (int)bit.size(); x += x&-x) {
      bit[x] += v;
    }
  }

  void reset() {
    fill(bit.begin(), bit.end(), 0);
  }
};

const int MAGIC = 400;

vector<tuple<int, int, int, int>> que;



int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int q;
  scanf("%d", &q);
  que.resize(q);
  vector<long long> ans(q, -1);
  for (int i = 0; i < q; ++i) {
    int t, l, r, x, y;
    scanf("%d %d %d", &t, &l, &r);
    --l;
    if (t == 1) {
      scanf("%d %d", &x, &y);
      --x;
      que[i] = make_tuple(l, r, x, y);
      ans[i] = 0;
    } else {
      que[i] = make_tuple(l, r, -1, -1);
    }
  }
  BIT bit(1e5 + 5);
  vector<bool> skip(n, false);
  for (int i = 0; i < q; i += MAGIC) {
    int til = min(i + MAGIC, q);
    fill(skip.begin(), skip.end(), false);
    vector<pair<int, int>> events; 
    for (int j = i; j < til; ++j) {
      if (get<3>(que[j]) == -1) {
        skip[get<0>(que[j])] = true;
      } else {
        int lef = get<0>(que[j]), rig = get<1>(que[j]);
        if (lef > 0)
          events.emplace_back(lef-1, ~j);
        events.emplace_back(rig-1, j);
      }
    }
    sort(events.begin(), events.end());
    auto it = events.begin();
    vector<int> skipped;
    bit.reset();
    for (int j = 0; j < n; ++j) {
      if (!skip[j]) {
        bit.upd(a[j], a[j]);
      } else {
        skipped.push_back(j);
      }
      while (it != events.end() && it->first <= j) {
        int id = it->second;
        if (id < 0) {
          id = ~id;
          ans[id] -= bit.get(get<3>(que[id])) - bit.get(get<2>(que[id]));
        } else {
          ans[id] += bit.get(get<3>(que[id])) - bit.get(get<2>(que[id]));
        }
        ++it;
      }
    }
    for (int j = i; j < til; ++j) {
      if (get<3>(que[j]) == -1) {
        a[get<0>(que[j])] = get<1>(que[j]);
      } else {
        int lef, rig, low, hig;
        tie(lef, rig, low, hig) = que[j];
        for (int z : skipped) {
          if (lef <= z && z < rig && low < a[z] && a[z] <= hig) {
            ans[j] += a[z];
          }
        }
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    if (ans[i] != -1) {
      printf("%lld\n", ans[i]);
    }
  }
  return 0;
}
