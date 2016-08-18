#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int dp[N];
vector<int> a;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    a.push_back(num);
  }
  sort(a.begin(), a.end());
  a.resize(distance(a.begin(), unique(a.begin(), a.end())));
  int mn = a[0];
  for(auto& it : a) {
    it -= mn;
  }
  for(int i = 0; i < N; i++) {
    dp[i] = N;
  }
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    if(dp[i] >= k) continue;
    for(int j = 0; j < a.size(); j++) {
      int to = i + a[j];
      dp[to] = min(dp[to], dp[i] + 1);
    }
  }
  for(int i = 0; i < N; i++) if(dp[i] <= k) printf("%d ", k * mn + i);
  return 0;
}