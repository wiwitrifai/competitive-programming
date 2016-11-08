#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e15;

int n, m, c; 
pair<pair<int, int>, int > b[N];

int f1(pair<int, int > p) {
  return p.first + p.second;
}
int f2(pair<int, int > p) {
  return p.first - p.second;
}

int dp[N];

int main() {
  freopen("bishops.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 0; i < m; i++) {
      int r, c, p;
      scanf("%d %d %d", &r, &c, &p);
      b[i] = {{r, c}, p};
    }
    int ans = 1;
    sort(b, b+m, [](pair< pair<int, int >, int > p, pair< pair<int, int>, int > q) {
      int pp = f1(p.first);
      int qq = f1(q.first);
      if (pp != qq)
        return pp < qq;
      return f2(p.first) < f2(q.first);
    });
    int last = f1(b[0].first);
    vector< pair<long long, long long > > seg;
    for (int i = 0; i < m; i++) {
      int now = f1(b[i].first);
      if (last != now) {
        sort(seg.begin(), seg.end());
        for (int j = 0; j < seg.size(); j++) {
          dp[j] = 1;
          int low = lower_bound(seg.begin(), seg.end(), make_pair(seg[j].second+1, -inf)) - seg.begin() - 1;
          if (low >= 0 && low < j)
            dp[j] += dp[low];
          if (j)
            dp[j] = max(dp[j], dp[j-1]);
          ans = max(ans, dp[j]);
        }
        seg.clear();
        last = now;
      }
      long long cur = f2(b[i].first);
      long long fir = cur + 2LL * b[i].second * b[i].second;
      long long sec = cur - 2LL * (1LL * b[i].second * b[i].second + c - 1);  
      seg.push_back({fir, sec});
    }
    if (seg.size()) {
      sort(seg.begin(), seg.end());
      for (int j = 0; j < seg.size(); j++) {
        dp[j] = 1;
        int low = lower_bound(seg.begin(), seg.end(), make_pair(seg[j].second+1, -inf)) - seg.begin() - 1;
        if (low >= 0 && low < j)
          dp[j] += dp[low];
        if (j)
          dp[j] = max(dp[j], dp[j-1]);
        ans = max(ans, dp[j]);
      }
      seg.clear();
    }
    sort(b, b+m, [](pair< pair<int, int >, int > p, pair< pair<int, int>, int > q) {
      int pp = f2(p.first);
      int qq = f2(q.first);
      if (pp != qq)
        return pp < qq;
      return f1(p.first) < f1(q.first);
    });
    last = f2(b[0].first);
    for (int i = 0; i < m; i++) {
      int now = f2(b[i].first);
      if (last != now) {
        sort(seg.begin(), seg.end());
        for (int j = 0; j < seg.size(); j++) {
          dp[j] = 1;
          int low = lower_bound(seg.begin(), seg.end(), make_pair(seg[j].second+1, -inf)) - seg.begin() - 1;
          if (low >= 0 && low < j)
            dp[j] += dp[low];
          if (j)
            dp[j] = max(dp[j], dp[j-1]);
          ans = max(ans, dp[j]);
        }
        seg.clear();
        last = now;
      }
      long long cur = f1(b[i].first);
      long long fir = cur + 2LL * b[i].second * b[i].second;
      long long sec = cur - 2LL * (1LL * b[i].second * b[i].second + c - 1);  
      seg.push_back({fir, sec});
    }
    if (seg.size()) {
      sort(seg.begin(), seg.end());
      for (int j = 0; j < seg.size(); j++) {
        dp[j] = 1;
        int low = lower_bound(seg.begin(), seg.end(), make_pair(seg[j].second+1, -inf)) - seg.begin() - 1;
        if (low >= 0 && low < j)
          dp[j] += dp[low];
        if (j)
          dp[j] = max(dp[j], dp[j-1]);
        ans = max(ans, dp[j]);
      }
      seg.clear();
    }
    printf("%d\n", ans);
  }
  return 0;
}