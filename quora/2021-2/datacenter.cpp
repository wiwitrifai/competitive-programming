#include <bits/stdc++.h>

using namespace std;

vector<long long> score;

template<class T>
struct BIT {
  vector<T> sum;
  BIT(int _n) : sum(_n+2, 0) {}
  void upd(int x, T v) {
    for (++x; x < (int)sum.size(); x += x&-x)
      sum[x] += v;
  }
  T get(int x) {
    T ret = 0;
    for (++x; x; x -= x&-x)
      ret += sum[x];
    return ret;
  }
};

void process(vector<tuple<int, int, int, int>> &events) {
  vector<int> allr, allc;
  allr.reserve(events.size());
  allc.reserve(events.size());
  for (auto & e : events) {
    int r, c;
    tie(r, c, ignore, ignore) = e;
    allr.push_back(r);
    allc.push_back(c);
  }
  auto vunique = [&](vector<int> & v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
  };
  // vunique(allr);
  vunique(allc);
  BIT<long long> sum(allc.size());
  BIT<int> cnt(allc.size());
  sort(events.begin(), events.end());
  for (auto & e : events) {
    int r, c, id, v;
    tie(r, c, id, v) = e;
    c = lower_bound(allc.begin(), allc.end(), c) - allc.begin();
    score[id] += sum.get(c-1) + 1LL * v * cnt.get(c-1);
    sum.upd(c, -v);
    cnt.upd(c, 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  score.resize(n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  vector<tuple<int, int, int, int>> events(n);
  for (int i = 0; i < n; ++i) {
    int r = -(x[i] + y[i]), c = x[i] - y[i];
    events[i] = {r, c, i, -y[i]};
  }
  process(events);
  for (int i = 0; i < n; ++i) {
    int r = y[i] - x[i], c = - (x[i] + y[i]);
    events[i] = {r, c, i, -x[i]};
  }
  process(events);
  for (int i = 0; i < n; ++i) {
    int r = x[i] + y[i], c = y[i] - x[i];
    events[i] = {r, c, i, y[i]};
  }
  process(events);
  for (int i = 0; i < n; ++i) {
    int r = x[i] - y[i], c = x[i] + y[i];
    events[i] = {r, c, i, x[i]};
  }
  process(events);
  printf("%d\n", (int)(min_element(score.begin(), score.end()) - score.begin() + 1));
  return 0;
}
