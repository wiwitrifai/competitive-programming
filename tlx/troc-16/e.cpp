#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int fp[N];

vector<pair<int, int>> pos[N];
int lef[N];

long long powmod(long long b, long long e) {
  long long r = 1;
  for (; e; e >>=1, b = b * b % mod)
    if (e & 1)
      r = r * b % mod;
  return r;
}

int main() {
  for (int i = 2; i < N; ++i) {
    if (fp[i]) continue;
    for (int j = i; j < N; j += i) {
      if (fp[j]) continue;
      fp[j] = i;
    }
  }
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    int now = a[i];
    while (now > 1) {
      int p = fp[now];
      int cnt = 0;
      while ((now % p) == 0) {
        now /= p;
        ++cnt;
      }
      pos[p].emplace_back(i, cnt);
    }
  }
  long long ans = 1;
  for (int p = 2; p < N; ++p) {
    if (pos[p].empty()) continue;
    stack<int> st;
    vector<pair<int, int>> & cur = pos[p];
    for (int i = 0; i < (int)pos[p].size(); ++i) {
      while (!st.empty() && cur[st.top()].second <= cur[i].second) {
        st.pop();
      }
      if (st.empty())
        lef[i] = 0;
      else
        lef[i] = cur[st.top()].first + 1;
      st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = (int)pos[p].size()-1; i >= 0; --i) {
      while (!st.empty() && cur[st.top()].second < cur[i].second) {
        st.pop();
      }
      int rig = n-1;
      if (st.empty())
        rig = n-1;
      else
        rig = cur[st.top()].first - 1;
      long long pp = powmod(p, cur[i].second);
      pp = powmod(pp, cur[i].first - lef[i] + 1);
      pp = powmod(pp, rig - cur[i].first + 1);
      ans = (ans * pp) % mod;
      st.push(i);
    }
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
