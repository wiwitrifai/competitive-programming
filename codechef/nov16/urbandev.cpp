#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long bit[N];

void upd(int x, int v) {
  for (; x < N; x += x & (-x))
    bit[x] += v;
}
long long get(int x) {
  long long ret = 0;
  for (; x; x -= x & (-x))
    ret += bit[x];
  return ret;
}
int x[N][2], y[N][2], id[N];

long long ans[N];

int main() {
  int n;
  scanf("%d", &n);
  vector< pair< pair<int, int >, pair<int, int > > > event;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
    if (x[i][0] == x[i][1]) {
      if (y[i][0] > y[i][1])
        swap(y[i][0], y[i][1]);
      assert(y[i][0] < y[i][1]);
      event.push_back({{x[i][0], i}, {y[i][0]-1, y[i][1]}});
    }
    else {
      assert(y[i][0] == y[i][1]);
      if (x[i][0] > x[i][1])
        swap(x[i][0], x[i][1]);
      assert(x[i][0] < x[i][1]);
      event.push_back({{x[i][0], -1-i}, {+1, y[i][0]}});
      event.push_back({{x[i][1]+1, -1-i-n}, {-1, y[i][0]}});
    }
  }
  long long tot1 = 0;
  sort(event.begin(), event.end());
  for (int i = 0; i < N; i++) {
    id[i] = -1;
    bit[i] = 0;
  }
  for (auto e : event) {
    if (e.first.second < 0) {
      upd(e.second.second, e.second.first);
      if (e.second.first > 0)
        id[e.second.second] = (-e.first.second-1) % n;
      else
        id[e.second.second] = -1;
    }
    else {
      ans[e.first.second] = get(e.second.second)-get(e.second.first);
      int idx = id[e.second.second];
      if (idx != -1 && (x[idx][0] == e.first.first || x[idx][1] == e.first.first))
        ans[e.first.second]--;
      idx = id[e.second.first+1];
      if (idx != -1 && (x[idx][0] == e.first.first || x[idx][1] == e.first.first))
        ans[e.first.second]--;
      assert(ans[e.first.second] >= 0);
      tot1 += ans[e.first.second];
    }
  }
  event.clear();
  for (int i = 0; i < n; i++) {
    if (y[i][0] == y[i][1]) {
      event.push_back({{y[i][0], i}, {x[i][0]-1, x[i][1]}});
    }
    else {
      assert(x[i][0] == x[i][1]);
      event.push_back({{y[i][0], -1-i}, {+1, x[i][0]}});
      event.push_back({{y[i][1]+1, -1-i-n}, {-1, x[i][0]}});
    }
  }
  sort(event.begin(), event.end());
  for (int i = 0; i < N; i++) {
    id[i] = -1;
    bit[i] = 0;
  }
  long long tot = 0;
  for (auto e : event) {
    if (e.first.second < 0) {
      upd(e.second.second, e.second.first);
      if (e.second.first > 0)
        id[e.second.second] = (-e.first.second-1) % n;
      else
        id[e.second.second] = -1;
    }
    else {
      ans[e.first.second] = get(e.second.second)-get(e.second.first);
      int idx = id[e.second.second];
      if (idx != -1 && (y[idx][0] == e.first.first || y[idx][1] == e.first.first))
        ans[e.first.second]--;
      idx = id[e.second.first+1];
      if (idx != -1 && (y[idx][0] == e.first.first || y[idx][1] == e.first.first))
        ans[e.first.second]--;
      assert(ans[e.first.second] >= 0);
      tot += ans[e.first.second];
    }
  }
  tot = 0;
  for (int i = 0; i < n; i++)
    tot += ans[i];
  tot /= 2;
  printf("%lld\n", tot);
  for (int i = 0; i < n; i++) {
    if (i)
      printf(" ");
    printf("%lld", ans[i]);
  }
  printf("\n");
  return 0;
}