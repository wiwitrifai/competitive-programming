#include "jump.h"

#include <bits/stdc++.h>

using namespace std;

struct DP {
  int n;
  int last_k;
  string s;
  vector< vector< int > > dp; 
  DP(string s) {
    last_k = -1;
    this->s = "0" + s + "0";
    n = this->s.size();
    for (int i = 0; i < n; i++) this->s[i] -= '0';
    dp.resize(n);
    for (int i = 0; i < n; i++) {
      dp[i].resize(n);
    }
  }
  void set(string s) {
    last_k = -1;
    this->s = "0" + s + "0";
    n = this->s.size();
    for (int i = 0; i < n; i++) this->s[i] -= '0';
    dp.resize(n);
    for (int i = 0; i < n; i++) {
      dp[i].resize(n);
    }
  }
  void precompute(int k) {
    if (k >= n)
      k = n-1;
    if (k == last_k) return;
    for (int i = 0; i < n; i++) {
      dp[i][i] = s[i];
      deque< int > dq;
      dq.push_back(i);
      for (int j = i+1; j < n; j++) {
        dp[i][j] = dp[i][dq.front()] + s[j];
        while (!dq.empty() && dp[i][dq.back()] >= dp[i][j])
          dq.pop_back();
        dq.push_back(j);
        if (dq.front() == j-k)
          dq.pop_front();
      }
    }
    last_k = k;
  }
  int get(int l, int r) {
    if (r >= n) r = n-1;
    if (r < l) return 0;
    return dp[l][r];
  }
};
vector< int > que[2017];
vector< pair< int, int > > seg;
vector< DP > sdp;
vector< int > sum;


vector<int> getMinimumPoints(int N, int Q, std::string S,
    std::vector<int> L, std::vector<int> R, std::vector<int> K) {
  int last = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '0') {
      if (last < i) {
        seg.emplace_back(last, i-1);
        sdp.push_back(DP(S.substr(last, i-last)));
      }
      last = i+1;
    }
  }
  if (last < N) {
    seg.emplace_back(last, N-1);
    sdp.push_back(DP(S.substr(last, N-last)));
  }
  vector<int> ans(Q);
  for (int i = 0; i <= 2000; i++) que[i].clear();
  for (int i = 0; i < Q; i++)
    que[min(K[i], 2000)].push_back(i);
  sum.resize(seg.size()+1);
  for (int k = 1; k <= 2000; k++) {
    if (que[k].empty()) continue;
    int cur = 0;
    sum[0] = cur;
    for (int j = 0; j < seg.size(); j++) {
      sdp[j].precompute(k);
      cur += sdp[j].get(0, N);
      sum[j+1] = cur;
    }
    for (int i : que[k]) {
      L[i]--; R[i]--;
      int le = upper_bound(seg.begin(), seg.end(), make_pair(L[i], N)) - seg.begin() - 1;
      int ri = upper_bound(seg.begin(), seg.end(), make_pair(R[i], N)) - seg.begin() - 1;
      if (le < 0) le = 0;
      if (le > ri) ans[i] = 0;
      else if (le == ri)
        ans[i] = (sdp[le].get(max(0, L[i]-seg[le].first+1), R[i]-seg[ri].first+1));
      else {
        ans[i] = sum[ri] - sum[le+1];
        ans[i] += (sdp[le].get(max(0, L[i]-seg[le].first+1), R[i]-seg[le].first+1));
        ans[i] += (sdp[ri].get(max(0, L[i]-seg[ri].first+1), R[i]-seg[ri].first+1));
      }
    }
  }
  return ans;
}