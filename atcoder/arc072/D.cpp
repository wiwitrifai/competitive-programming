#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int dp[N][N];

int grund(int u, int v) {
  if (u > v) swap(u, v);
  if (dp[u][v] != -1) return dp[u][v];
  int & ret = dp[u][v];
  set< int > st;
  for (int i = 2; i <= u; i += 2) {
    st.insert(grund(u-i, v + i/2));
  }
  for (int i = 2; i <= v; i += 2) {
    st.insert(grund(u+i/2, v - i));
  }
  ret = 0;
  for (int v : st)
    ret += ret == v;
  return ret;
}

int main() {
  // memset(dp, -1, sizeof dp);
  // for (int i = 0; i <= 100; i++) {
  //   for (int j = 0; j <= 100; j++) {
  //     // cerr << grund(i, j) << " ";
  //     if (abs(i-j) <= 1) {
  //       assert(grund(i, j) == 0);
  //       if (grund(i, j) == 0 && i <= j)
  //         cerr << i << " " << j << endl;
  //     }
  //     else
  //       assert(grund(i, j) > 0);
  //   }
  //   // cerr << endl;
  // }
  long long a, b;
  cin >> a >> b;
  if (abs(a-b) <= 1)
    puts("Brown");
  else
    puts("Alice");
  return 0;
}