#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int cnt[N];
pair<int, int> val[N];

int main() {
  for (int i = -600; i <= 600; ++i) {
    for (int j = -600; j <= 600; ++j) {
      ++cnt[i*i + j * j];
    }
  }
  int ma = 0;
  for (int i = 0; i < N; ++i)
    ma = max(ma, cnt[i]), val[i] = {cnt[i], i};
  sort(val, val+N);
  reverse(val, val+N);
  for (int i = 0; i < 10; ++i)
    cerr << val[i].first << " " << val[i].second << endl;
  cerr << ma << endl;
  return 0;
}