#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> cor[N];

bool bad(pair<int, int> a, pair<int, int> b) {
  return b.second - (b.first - a.first) >= a.second;
}
bool good(pair<int, int> a, pair<int, int> b) {
  return a.second - (b.first - a.first) < b.second;
}

long long calc(int n) {
  return 1LL * n * n;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    cor[i] = {y, x};
  }
  sort(cor, cor+n);
  vector<pair<int, int> > st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && bad(st.back(), cor[i])) st.pop_back();
    if (st.empty() || good(st.back(), cor[i]))
      st.push_back(cor[i]);
  }
  long long ans = 0;
  for (int i = 0; i < st.size(); ++i) {
    cerr << st[i].first << " " << st[i].second << endl;
    ans += calc(st[i].second);
    if (i) {
      int l = st[i-1].first, r = st[i].first, p = -1;
      if (st[i-1].second < st[i].second) {
        int d = st[i].second - st[i-1].second;
        r -= d;
        p = st[i-1].second;
      }
      else {
        int d = st[i-1].second - st[i].second;
        l += d;
        p = st[i].second;
      }
      if ((r-l) & 1) {
        int d = (r-l) / 2;
        l += d;
        r -= d;
        p -= d;
        if (p > 0) {
          ans -= 1LL * p * (p-1);
        }
      }
      else {
        int d = (r-l) / 2;
        l += d;
        r -= d;
        p -= d;
        if (p > 0)
          ans -= 1LL * p * p;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
