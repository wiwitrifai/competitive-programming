#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

char s[N];
int n;
int p[] = {11, 13};
int pp[2];
int mod[] = {int(1e9+7), int(1e9+9)};

const vector<long long> MOD = {99999999999999997LL, 100000000000000003LL};

bool check_string(int N, const string &S) {
  int H = MOD.size();
  vector<vector<long long>> ten(H, vector<long long>(N, 1));
  for (int i = 0; i < H; ++i) {
    for (int j = 1; j < N; ++j) {
      ten[i][j] = (ten[i][j - 1] * 10) % MOD[i];
    }
  }
  map<vector<long long>, int> visited;
  vector<long long> current(H, 0);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < N; ++j) {
      current[i] = (current[i] * 10 + S[j] - '0') % MOD[i];
    }
  }
  visited[current] = 0;
  for (int j = N; j < (int)S.size(); ++j) {
    for (int i = 0; i < H; ++i) {
      current[i] = (current[i] - (S[j - N] - '0') * ten[i][N - 1]) % MOD[i];
      if (current[i] < 0) {
        current[i] += MOD[i];
      }
      current[i] = (current[i] * 10 + S[j] - '0') % MOD[i];
    }
    if (visited.count(current)) {
      int off = j-N+1;
      for (int k = 0; k < N; ++k) {
        cerr << S[off+k];
      }
      cerr << endl;
      off = visited[current];
      for (int k = 0; k < N; ++k) {
        cerr << S[off+k];
      }
      cerr << endl;
      for (int k = 0; k < MOD.size(); ++k) {
        cerr << current[k] << " ";
      }
      cerr << endl
;      return false;
    }
    visited[current] = j - N + 1;
  }
  return true;
}

int main() {
  scanf("%s %d", s, &n);
  for (int i = 0; i < 2; ++i) {
    pp[i] = 1;
    for (int j = 0; j < n-1; ++j)
      pp[i] = 1LL * pp[i] * p[i] % mod[i];
  }
  int len = strlen(s);
  for (int i = 0; i < len; ++i)
    s[i] -= '0';
  set<pair<int, int> > st;
  int h[2];
  memset(h, 0, sizeof h);
  cerr << len - n + 1 << endl;
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < 2; ++j) {
      h[j] = (1LL * h[j] * p[j] + s[i]) % mod[j];
    }
  }
  for (int i = n-1; i < len; ++i) {
    for (int j = 0; j < 2; ++j) {
      h[j] = (1LL * h[j] * p[j] + s[i]) % mod[j];
      if (h[j] < 0) h[j] += mod[j];
    }
    pair<int, int> now = make_pair(h[0], h[1]);
    assert(!st.count(now));
    st.insert(now);
    for (int j = 0; j < 2; ++j) {
      h[j] = (h[j] - 1LL * pp[j] * s[i-(n-1)]) % mod[j];
      if (h[j] < 0) h[j] += mod[j];
    }
  }
  cerr << " ok " << endl;
  string ss(len, '0');
  for (int i = 0; i < len; ++i)
    ss[i] += s[i];
  cerr << check_string(n, ss) << endl;
  return 0;
}