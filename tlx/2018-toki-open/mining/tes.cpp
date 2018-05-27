#include <bits/stdc++.h>

using namespace std;

const long long N = 2e6 + 6;

bool sq[N];

int main() {
  for (int i = 0; i * i < N; ++i) {
    sq[i * i] = 1;
  }
  vector<pair<int, int> > vp;
  int ma = 0;
  for (int i = 1; i < 1000; ++i) {
    int cnt = 0;
    for (int j = 1; j < 1000; ++j) {
      int v = i * i + j * j;
      if (sq[v]) {
        vp.emplace_back(i, j);
        ++cnt;
      }
    }
    ma = max(ma, cnt);
  }
  cerr << ma << endl;
  cerr << vp.size() << endl;
  return 0;
}