#include <bits/stdc++.h>

using namespace std;

const int mi = 50;

int w[1000];

int main() {
  time_t start_t = clock();
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", w+i);
    sort(w, w+n);
    int cnt = n;
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
      if (cnt * w[i] < mi)
        break;
      int now = (mi + w[i] - 1) / w[i];
      assert(cnt >= now && now * w[i] >= mi);
      cnt -= now;
      ans++;
    }
    printf("Case #%d: %d\n", tc, ans);
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}