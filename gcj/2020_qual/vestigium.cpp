#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }
  int trace = 0;
  for (int i = 0; i < n; ++i) {
    trace += matrix[i][i];
  }
  int c = 0, r = 0;

  for (int i = 0; i < n; ++i) {
    set<int> st;
    for (int j = 0; j < n; ++j) {
      st.insert(matrix[j][i]);
    }
    if ((int)st.size() != n) {
      ++c;
    }
    st.clear();
    for (int j = 0; j < n; ++j) {
      st.insert(matrix[i][j]);
    }
    if ((int)st.size() != n) {
      ++r;
    }
  }
  printf("%d %d %d\n", trace, r, c);
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
