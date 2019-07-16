#include <bits/stdc++.h>

using namespace std;

const int N = 250500;

pair<long long, int> ballons[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld %d", &ballons[i].first, &ballons[i].second);
  }
  sort(ballons, ballons+n, [](pair<long long, int> le, pair<long long, int> ri) {
    long long vle = ri.first - le.second, vri = le.first - ri.second;
    if (vle == vri)
      return le.first < ri.first;
    return vle > vri;
  });
  long long now = 0;
  int ans = 0;
  priority_queue<long long> pq;
  for (int i = 0; i < n; ++i) {
    if (ballons[i].first >= now) {
      ++ans;
      now += ballons[i].second;
      pq.push(ballons[i].second);
    }
    else if (!pq.empty() && pq.top() > ballons[i].second) {
      now -= pq.top();
      now += ballons[i].second;
      pq.pop();
      pq.push(ballons[i].second);
    }
  }
  printf("%d\n", ans);
  return 0;
}
