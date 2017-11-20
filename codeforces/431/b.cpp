#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int g[N], p[N], t[N], n, h, w;

int to[N];

map<int, queue<int> > mq, asli;

int main() {
  scanf("%d %d %d", &n, &w, &h);
  vector<pair<int, int > > vx;
  vector<pair<int, int > > vy;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", g+i, p+i, t+i);
    if (g[i] == 2)
      vx.emplace_back(-p[i], i);
    else
      vy.emplace_back(p[i], i);
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  for (auto it : vx) {
    int id = it.second;
    mq[t[id]-p[id]].push(id);
  }
  asli = mq;
  for (auto it : vy) {
    int id = it.second;
    // cerr << id << endl;
    auto cur = mq.find(t[id] - p[id]);
    if (cur != mq.end()) {
      cur->second.push(id);
      int w = cur->second.front();
      cur->second.pop();
      // cerr << " " << w << " = " << id << endl;
      to[w] = id;
    }
    else
      to[id] = id;
  }
  for (auto it : mq) {
    queue<int> qa = asli[it.first];
    while (!it.second.empty() && !qa.empty()) {
      to[it.second.front()] = qa.front();
      it.second.pop();
      qa.pop();
    }
  }
  for (int i = 0; i < n; i++) {
    // cerr << i << " -> " << to[i] << endl;
    int id = to[i];
    if (g[id] == 1)
      printf("%d %d\n", p[id], h);
    else
      printf("%d %d\n", w, p[id]);
  }
  return 0;
}