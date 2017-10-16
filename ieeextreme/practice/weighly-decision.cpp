#include <bits/stdc++.h>

using namespace std;
const int inf = 1e8;

map<vector<int>, int > dp;
vector<int> st;

bool check(vector<int> now) {
  for (int i = 0, j = 0; i < now.size(); i++) {
    while (j < st.size() && st[j] < now[i]) j++;
    if (j == st.size()) return false;
    j++;
  }
  return true;
}

const int N = 22;
int d[N][N];
int calc(vector<pair<int, int > > now) {
  int n = now.size();
  for (int i = 0; i < n; i++) {
    d[i][i] = now[i].first;
  }
  for (int len = 1; len < n; len++) {
    for (int i = 0; i+len < n; i++) {
      d[i][i+len] = inf;
      for (int j = 0; j <= len; j++) {
        if (now[i+j].second == 0) continue;
        int cur = 0;
        cur = d[i+j][i+j];
        if (j > 0)
          cur = max(cur, d[i][i+j-1]);
        if (j < len)
          cur = max(cur, d[i+j+1][i+len]);
        d[i][i+len] = min(d[i][i+len], cur+1);
      }
      for (int j = 0; j < len; j++) {
        d[i][i+len] = min(d[i][i+len], max(d[i][i+j], d[i+j+1][i+len]) + 1);
      }
    }
  }
  return d[0][n-1];
}

int solve(vector<int> now) {
  if (dp.count(now))
    return dp[now];
  vector<int> add, inc;
  add = now;
  inc = now;
  add.push_back(1);
  vector<pair<int, int> > params;
  if (check(add))
    params.emplace_back(solve(add), 0); 
  for (int i = (int)now.size()-1; i >= 0; i--) {
    inc[i]++;
    if (check(inc))
      params.emplace_back(solve(inc), 1);
    inc[i]--;
    swap(add[i], add[i+1]);
    if (check(add))
      params.emplace_back(solve(add), 0);
  }
  return dp[now] = calc(params);
}

int solve2(vector<int> w) {
  sort(w.begin(), w.end());
  int cnt = 1;
  st.clear();
  for (int i = 1; i < w.size(); i++) {
    if (w[i] != w[i-1])
      st.push_back(cnt), cnt = 1;
    else
      cnt++;
  }
  st.push_back(cnt);
  dp.clear();
  dp[st] = 0;
  return solve(vector<int>(1, 1));
}

int coba(vector<int> w) {
  int res = solve2(w);
  sort(w.begin(), w.end());
  int nmask = 1 << w.size();
  vector<set<vector<int> > > menang(w.size()+1), kalah(w.size()+1), imbang(w.size() + 1);
  for (int mask = 1; mask < nmask; mask++) {
    vector<int> le, ri;
    int sle = 0, sri = 0;
    for (int i = 0; i < w.size(); i++)
      if (mask & (1 << i))
        le.push_back(w[i]), sle += w[i];
      else
        ri.push_back(w[i]), sri += w[i];
    if (le < ri) {
      kalah[le.size()].insert(le);
      menang[ri.size()].insert(ri);
    }
    else if (le > ri) {
      menang[le.size()].insert(le);
      kalah[ri.size()].insert(ri);
    }
    else {
      imbang[le.size()].insert(le);
      imbang[ri.size()].insert(ri);
    }
  }
  for (int i = 1; i <= (int)w.size()-i; i++) {
    if (kalah[i].size() > 1 || menang[i].size() > 1 || imbang[i].size() > 1) continue;
    int j = (int)w.size()-i;
    if (kalah[j].size() > 1 || menang[j].size() > 1 || imbang[j].size() > 1) continue;
    int cur = 0;
    if (kalah[i].size() == 1 && menang[j].size() == 1) {
      cur = max(cur, coba(*kalah[i].begin()) + coba(*menang[j].begin()) + 1);
    }
    if (menang[i].size() == 1 && kalah[j].size() == 1) {
      cur = max(cur, coba(*menang[i].begin()) + coba(*kalah[j].begin()) + 1);
    }
    if (imbang[i].size() == 1 && imbang[j].size() == 1) {
      cur = max(cur, coba(*imbang[i].begin()) + coba(*imbang[j].begin()) + 1);
    }
    res = min(res, cur);
  }
  return res;
}

int main() {
  vector<int> w;
  int x;
  while (scanf("%d", &x) == 1)
    w.push_back(x);
  cerr << solve2(w) << endl;
  printf("%d\n", coba(w));
  return 0;
}