#include <bits/stdc++.h>

using namespace std;

void read_input() {
}

void solve() {
  int n;
  scanf("%d", &n);
  priority_queue<int> pq;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    pq.push(-a);
    while ((int)pq.size() > ans) {
      while (!pq.empty() && -pq.top() <= ans) pq.pop();
      if ((int)pq.size() > ans)
        ++ans;
      else
        break;
    }
    printf("%d%c", ans, i+1 == n ? '\n' : ' ');
  }
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
