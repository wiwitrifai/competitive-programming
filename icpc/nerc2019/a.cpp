#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;

long long a[N], b[N], t[N];
int n;
queue<int> que;

int main() {
  scanf("%d", &n);
  vector<pair<long long, int>> events;
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld %lld", a+i, b+i, t+i);
    events.emplace_back(a[i], i);
    events.emplace_back(b[i], ~i);
  }
  sort(events.begin(), events.end());
  int iv = 0;
  long long now = 0;
  set<pair<long long, int>> st;
  auto add = [&](int i) {
    st.insert(make_pair(t[i], i));
  };
  auto rem = [&](int i) {
    st.erase(make_pair(t[i], i));
  };
  auto shortest = [&]() {
    if (st.empty())
      return inf;
    return st.begin()->first;
  };
  long long ans = 0;
  while (iv < (int)events.size()) {
    if (st.empty()) {
      assert(events[iv].second >= 0);
      add(events[iv].second);
      now = events[iv].first;
      ++iv;
      continue;
    }
    long long cur = events[iv].first, jmp = shortest();
    long long k = (cur - now) / jmp;
    ans += k;
    now += k * jmp;
    long long newshortest = inf + 5;
    while (iv < (int)events.size() && events[iv].first < min(now + shortest(), newshortest)) {
      int v = events[iv].second;
      if (v < 0) {
        rem(~v);
      }
      else {
        que.push(v);
        newshortest = min(newshortest, a[v] + t[v]);
      }
      ++iv;
    }
    if (!st.empty() || !que.empty()) {
      ++ans;
    }
    now = min(now + shortest(), newshortest);
    while (!que.empty()) {
      add(que.front());
      que.pop();
    }
  }
  printf("%lld\n", ans);
  return 0;
}
