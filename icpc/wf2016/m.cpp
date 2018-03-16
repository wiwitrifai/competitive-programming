#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int own[N][N];

int s[N], b[N], a[N], prior_ceil[N], cp[N], pc[N], ans[N];
int owned[N], blocked[N];
char ch[N];

vector<pair<char, int> > command[N];

int main() {
  int t, r;
  scanf("%d %d", &t, &r);
  for (int i = 1; i <= t; ++i) {
    scanf("%d %d %d", s+i, b+i, a+i);
    for (int j = 0; j < a[i]; ++j) {
      scanf("%s", ch);
      int no = stoi(ch+1);
      command[i].push_back(make_pair(ch[0], no));
      if (ch[0] == 'L') {
        prior_ceil[no] = max(prior_ceil[no], b[i]);
      }
    }
    reverse(command[i].begin(), command[i].end());
  }
  int clock = 0;
  set<int> active;
  priority_queue<pair<int, int> > wait;
  for (int i = 1; i <= t; ++i)
    wait.push(make_pair(-s[i], i));
  while (active.size() + wait.size() > 0) {
    if (active.empty()) {
      clock = max(-wait.top().first, clock);
    }
    while (wait.size() > 0 && -wait.top().first <= clock) {
      active.insert(wait.top().second);
      wait.pop();
    }
    fill(cp, cp+t+1, -1);
    for (auto v : active)
      cp[v] = b[v];
    for (int i = 1; i <= t; ++i) {
      pc[i] = 0;
      if (cp[i] < 0) continue;
      for (int j = 1; j <= r; ++j)
        if (own[i][j])
          pc[i] = max(pc[i], prior_ceil[j]);
    }
    int se = *active.begin();
    fill(blocked, blocked+t+1, 0);
    for (int i = 1; i <= t; ++i) {
      if (cp[i] < 0) continue;
      if (command[i][a[i]-1].first == 'L') {
        int no = command[i][a[i]-1].second;
        if (owned[no]) {
          blocked[i] = owned[no];
          cp[owned[no]] = max(cp[owned[no]], cp[i]);
        }
      }
    }
    priority_queue<pair<int, int> > pq;
    for (int v : active)
      pq.push(make_pair(-cp[v], v));
    while (!pq.empty()) {
      int cost = -pq.top().first, v = pq.top().second;
      pq.pop();
      if (cost != cp[v]) continue;
      if (command[v][a[v]-1].first != 'L') continue;
      for (int u : active) {
        if (pc[u] >= cp[v] && cp[u] < cp[v]) {
          cp[u] = cp[v];
          pq.push(make_pair(-cp[u], u));
          if (blocked[v] == 0)
            blocked[v] = -1;
        }
      }
      if (blocked[v] > 0) {
        int u = blocked[v];
        if (cp[u] < cp[v]) {
          cp[u] = cp[v];
          pq.push(make_pair(-cp[u], u));
        }
      }
    }
    se = -1;
    for (int i : active) {
      if (blocked[i]) continue;
      if (se == -1 || cp[se] < cp[i])
        se = i;
    }
    --a[se];
    int no = command[se][a[se]].second;
    if (command[se][a[se]].first == 'C') {
      if (wait.size() > 0 && -wait.top().first < clock + no) {
        no = -wait.top().first - clock;
        command[se][a[se]].second -= no;
        ++a[se];
      }
      clock += no;
    }
    else if (command[se][a[se]].first == 'L')
      own[se][no] = 1, owned[no] = se;
    else
      own[se][no] = 0, owned[no] = 0;
    if (a[se] == 0) {
      active.erase(se);
      ans[se] = clock;
    }
  }
  for (int i = 1; i <= t; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
