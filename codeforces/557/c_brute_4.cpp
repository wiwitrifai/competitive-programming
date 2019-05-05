#include <bits/stdc++.h>

using namespace std;

const int N = 6;

int grund[N][N][N][N];

int main() {
  vector<int> vmask;
  for (int mask = 1; mask < (1 << 4); ++mask) {
    if (__builtin_popcount(mask) == 2)
      vmask.push_back(mask);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        for (int z = 0; z < N; ++z) {
          int a[4];
          a[0] = i;
          a[1] = j;
          a[2] = k;
          a[3] = z;
          int cnt = 0;
          for (int x = 0; x < 4; ++x) {
            cnt += a[x] > 0;
          }
          if (cnt < 2) {
            grund[i][j][k][z] = 0;
            continue;
          }
          set<int> st;
          for (int mask : vmask) {
            vector<int> id;
            for (int x = 0; x < 4; ++x) {
              if (mask & (1 << x))
                id.push_back(x);
            }
            assert(id.size() == 2);
            for (int p = 1; p <= a[id[0]]; ++p) {
              for (int q = 1; q <= a[id[1]]; ++q) {
                a[id[0]] -= p;
                a[id[1]] -= q;
                st.insert(grund[a[0]][a[1]][a[2]][a[3]]);
                a[id[0]] += p;
                a[id[1]] += q;
              }
            }
          }
          int now = 0;
          for (int x : st)
            now += x == now;
          grund[i][j][k][z] = now;
        }
      }
    }
  }
  return 0;
}
