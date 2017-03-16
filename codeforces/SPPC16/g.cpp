#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

priority_queue<tuple<int, int, int>> need[8];       // prioritas - orang - id
priority_queue<tuple<long long, int, int>> offer;   // time - orang - id

vector<tuple<int, int, int>> a[N];                  // time - prioritas - mask
int ada[3], d[N];

long long ans[N];

int get_ada() {
  int mask = 0;
  for (int i = 0; i < 3; i++) if (ada[i]) {
    mask |= (1 << i);
  }
  return mask;
}

tuple<int, int, int> get_need() {
  tuple<int, int, int> ret = make_tuple(-1, -1, -1);
  int mask_ada = get_ada();
  int at = -1;
  for (int i = 0; i < 8; i++) {
    if ((mask_ada & i) == i && need[i].size()) {
      if (need[i].top() > ret) {
        ret = need[i].top();
        at = i;
      }
    }
  }
  if (at != -1) {
    need[at].pop();
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++) cin >> ada[i];
  for (int i = 0; i < n; i++) cin >> d[i];
  cin.ignore();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d[i]; j++) {
      int t, p;
      string str, buf;
      getline(cin, str);
      stringstream ss(str);
      ss >> buf;
      t = atoi(buf.c_str());
      ss >> buf;
      p = atoi(buf.c_str());
      int mask = 0;
      while (ss >> buf) {
        if (buf == "Camera") {
          mask |= 1;
        } else if (buf == "Camcorder") {
          mask |= 2;
        } else if (buf == "Computer") {
          mask |= 4;
        }
      }
      a[i].emplace_back(t, p, mask);
    }
  }
  for (int i = 0; i < n; i++) {
    int t, p, m;
    tie(t, p, m) = a[i][0];
    need[m].emplace(p, i, 0);
  }
  while (1) {
    // prioritas - orang - id
    tuple<int, int, int> ret;
    int p, user, id;
    tie(p, user, id) = get_need();
    if (p == -1) break;
    int t, m;
    tie(t, p, m) = a[user][id];
    offer.emplace(-t, user, id);
    for (int i = 0; i < 3; i++) {
      if (m & (1 << i)) {
        ada[i]--;
      }
    }
  }
  while (!offer.empty()) {
    long long time_now;
    tie(time_now, ignore, ignore) = offer.top();
    while (!offer.empty()) {
      long long now;
      int user, id;
      tie(now, user, id) = offer.top();
      if (time_now != now) break;
      offer.pop();
      ans[user] = -now;
      int t, p, m;
      tie(t, p, m) = a[user][id];
      for (int i = 0; i < 3; i++) {
        if (m & (1 << i)) {
          ada[i]++;
        }
      }
      if (id + 1 < d[user]) {
        tie(t, p, m) = a[user][id + 1];
        need[m].emplace(p, user, id + 1);
      }
    }
    while (1) {
      // prioritas - orang - id
      tuple<int, int, int> ret;
      int p, user, id;
      tie(p, user, id) = get_need();
      if (p == -1) break;
      int t, m;
      tie(t, p, m) = a[user][id];
      offer.emplace(time_now - t, user, id);
      for (int i = 0; i < 3; i++) {
        if (m & (1 << i)) {
          ada[i]--;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) printf("%I64d ", ans[i]);

  return 0;
}