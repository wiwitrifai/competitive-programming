#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

vector<int> online[N];
int add[N];

int p[N], cnt[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[v] < -p[u])
    swap(u, v);
  p[v] += p[u];
  cnt[v] += cnt[u];
  p[u] = v;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<int> timeframe;
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    online[i].resize(t * 2);
    for (int j = 0; j < t; ++j) {
      int a, b;
      scanf("%d %d", &a, &b);
      ++b;
      online[i][j * 2] = a;
      online[i][j * 2 + 1] = b;
      timeframe.push_back(a);
      timeframe.push_back(b);
    }
  }
  memset(p, -1, sizeof p);
  sort(timeframe.begin(), timeframe.end());
  timeframe.erase(unique(timeframe.begin(), timeframe.end()), timeframe.end());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)online[i].size(); j += 2) {
      int & a = online[i][j];
      int & b = online[i][j+1];
      a = lower_bound(timeframe.begin(), timeframe.end(), a) - timeframe.begin();
      b = lower_bound(timeframe.begin(), timeframe.end(), b) - timeframe.begin();
      ++add[a];
      --add[b-1];
    }
    ++cnt[find(online[i][0])];
    for (int j = 1; j + 1 < (int)online[i].size(); j += 2) {
      int b_prev = online[i][j];
      int a_next = online[i][j+1];
      merge(b_prev-1, a_next);
    }
  }
  int sum = 0;
  for (int i = 0; i + 1 < (int)timeframe.size(); ++i) {
    sum += add[i];
    if (sum > 0)
      merge(i, i+1);
  }
  for (int i = 0; i < q; ++i) {
    int p;
    scanf("%d", &p);
    --p;
    printf("%d\n", cnt[find(online[p][0])]);
  }
  return 0;
}
