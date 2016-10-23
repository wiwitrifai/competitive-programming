#include <bits/stdc++.h>

using namespace std;

const int N = 10, M = 6;

struct state
{
  int a[N];
  state() {
    memset(a, 0, sizeof a);
  }
  int & operator[] (int id) {
    return a[id];
  }
  int operator[] (int id) const {
    return a[id];
  }
  bool operator<(const state s) const {
    for (int i = 0; i < N; i++)
      if (s[i] != a[i])
        return a[i] < s[i];
    return false;
  }
};

state st;

map< state, long long > dp;

void generate(int id, int n, int last) {
  if (id >= n) {
    state next = st;
    for (int i = n-1; i >= 0; i--) {
      for (int j = st[i]-1; j >= 0; j--) {
        int cur = j;
        for (int k = i; k < n; k++) {
          cur = min(cur, st[k]);
          next[k] = cur;
        }
        dp[next] += dp[st];
      }
    }
    // for (int i = 0; i < N; i++) {
    //   cerr << st[i];
    // }
    // cerr << " = " << dp[st] << endl;
    return;
  }
  for (int i = last; i >= 0; i--) {
    st[id] = i;
    generate(id + 1, n, i);
  }
}

int main() {
  for (int n = 1; n < N; n++) {
    for (int m = 1; m < N; m++) {
      dp.clear();
      for (int i = 0; i < n; i++)
        st[i] = m;
      for (int i = n; i < N; i++)
        st[i] = 0;
      dp[st] = 1;
      // cerr << n << " " << m << endl;
      generate(0, n, m);
      for (int i = 0; i < N; i++)
        st[i] = 0;
      cout << dp[st] << "\t";
    }
    cout << endl;
  }
  return 0;
}