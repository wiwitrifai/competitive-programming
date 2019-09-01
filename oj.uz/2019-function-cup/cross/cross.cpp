#include "cross.h"
#include <bits/stdc++.h>

using namespace std;

long long SelectCross(int K, std::vector<int> I, std::vector<int> O) {
  int N = I.size();
  vector<pair<int, int>> pairs(N);
  for (int i = 0; i < N; ++i) {
    pairs[i] = {I[i], O[i]};
  }
  sort(pairs.begin(), pairs.end());
  reverse(pairs.begin(), pairs.end());
  priority_queue<int> pq;
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    pq.push(-pairs[i].second);
    while (pq.size() > K) {
      pq.pop();
    }
    if (pq.size() == K) {
      int din = pairs[i].first, dout = -pq.top();
      ans = max(ans, 1LL * dout * dout - 1LL * (dout - din) * (dout - din));
    }
  }
	return ans;
}
