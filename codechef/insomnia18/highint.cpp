#include <bits/stdc++.h>

using namespace std;

const int mod = 786433;
const int N = 786433;

bitset<N> bs[50];

bool cek(int p, int n) {
  long long now = 1;
  for (int i = 1; i < n; ++i) {
    now = now * p % mod;
    if (now == 1) return false;
  }
  now = now * p % mod;
  return now == 1;
}

int main() {
  vector<pair<int, bitset<N> > > cand;
  bitset<N> all;
  all[0] = 1;
  int n = 1 << 18;
  for (int p = 2; p < N && cand.size() <  1000; ++p) {
    if (all[p] || !cek(p, n)) continue;
    cerr << cand.size() << " " << p << endl;
    bitset<N> cur;
    long long now = 1;
    for (int i = 1; i < mod; ++i) {
      now = now * p % mod;
      cur[now] = 1;
    }
    all = all | cur;
    cand.push_back(make_pair(p, cur));
    cerr << all.count() << endl;
    if (all.count() >= N) break;
  }

  return 0;
}