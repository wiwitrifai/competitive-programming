#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, m, l, d, w[N];

int main() {
  time_t startt = clock();
  cerr << "Preprocessing done! time: " << (double)(clock() - startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d %d %d %d", &l, &n, &m, &d);
    for (int i = 1; i <= n; i++) {
      scanf("%d", w+i);
    }
    priority_queue< pair<long long, int > > pq;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      pq.push(make_pair(-w[i], i)); 
    }
    while (!pq.empty()) {
      pair< long long, int > top = pq.top();
      pq.pop();
      if (!top.second) {
        ans = -top.first;
        if (m < 0)
          pq.push(make_pair(top.first - d, 0));
        m++;
        continue;
      }
      else if (l > 0) {
        l--;
        if (m > 0)
          pq.push(make_pair(top.first-d, 0));
        m--;
        pq.push(make_pair(top.first-w[top.second], top.second));
      }
    }

    printf("Case #%d: %lld\n", tc, ans);

    cerr << "TC#" << tc << " done! time: " << (double)(clock() - startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  cerr << "Finihed!" << endl;
  return 0;
}