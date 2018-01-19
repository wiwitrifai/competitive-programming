#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[55];
vector<pair<int, int> > le[N];
vector<pair<int, int> > ri[N];

void removeDuplicate(vector<pair<int, int> > & v) {
  if (v.empty()) return;
  sort(v.begin(), v.end());
  vector<pair<int, int> > res;
  int last = v[0].first;
  int val = v[0].second;
  for (auto it : v) {
    if (last != it.first) {
      res.push_back({last, val});
      last = it.first;
      val = it.second;
    }
    val = min(val, it.second);
  }
  res.push_back({last, val});
  v = res;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%s %d", s, &x);
    ++x;
    for (int i = 1; i <= x; ++i)
      le[i].clear(), ri[i].clear();
    int n = strlen(s);
    int a = n/2, b = n - a;
    int nmask = 1 << a;
    int cur = 0;
    for (int i = 0; i < a; ++i)
      if (s[i] == '1')
        cur |= 1 << i;
    for (int mask = 1; mask < nmask; mask += 2) {
      int one = 0, zero = 1;
      for (int i = 0; i < a; ++i) {
        if (mask & (1 << i))
          one += zero;
        else
          zero += one;
      }
      if (one > x || zero > x) continue;
      le[one].push_back({zero, __builtin_popcount(mask^cur)});
    }
    nmask = 1 << (b-1);
    cur = 0;
    for (int i = 0; i < b; ++i)
      if (s[a+i] == '1')
        cur |= 1 << i;
    for (int mask = 0; mask < nmask; ++mask) {
      int one = 1, zero = 0;
      for (int i = b-1; i >= 0; --i) {
        if (mask & (1 << i))
          one += zero;
        else
          zero += one;
      }
      if (one > x || zero > x) continue;
      ri[zero].push_back({one, __builtin_popcount(mask^cur)});
    }
    for (int i = 1; i <= x; ++i)
      removeDuplicate(le[i]);
    for (int i = 1; i <= x; ++i)
      removeDuplicate(ri[i]);
    int ans = n+1;
    for (int i = 1; i <= x; ++i) {
      for (int j = 1; j <= x; ++j) {
        if (i * j > x) break;
        int cur = x - i * j;
        if (le[i].size() < ri[j].size()) {
          for (auto it : le[i]) {
            if (cur % it.first) continue;
            int s = cur / it.first;
            auto res = lower_bound(ri[j].begin(), ri[j].end(), make_pair(s, -1));
            if (res == ri[j].end() || res->first != s) continue;
            ans = min(ans, it.second + res->second);
          }
        }
        else {
          for (auto it : ri[j]) {
            if (cur % it.first) continue;
            int s = cur / it.first;
            auto res = lower_bound(le[i].begin(), le[i].end(), make_pair(s, -1));
            if (res == le[i].end() || res->first != s) continue;
            ans = min(ans, it.second + res->second);
          }
        }
      }
    }
    if (ans > n) puts("NO");
    else printf("YES\n%d\n", ans);
  }
  return 0;
}