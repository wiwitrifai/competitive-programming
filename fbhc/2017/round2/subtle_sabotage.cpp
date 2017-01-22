#include <bits/stdc++.h>

using namespace std;

int main() {
  time_t start_t = clock();
  cerr << "Precompute done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl; 
  cerr << "START!" << endl;
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    if (n > m)
      swap(n, m);
    int ans = -1;
    if (n/k == 1 && n > k) {
      if (m >= 2 * k + 3)
        ans = 2;
    }
    else if (n == 2 * k) {
      if (m >= 2 * k + 3)
        ans = 2;
    }
    else if (n/k == 2 && n > 2 * k) {
      if (m >= 2 * k + 3)
        ans = 3;
    }
    else if (n == 3 * k) {
      if (m >= 2 * k + 3)
        ans = 3;
    }
    else if (n/k == 3 && n > 3 * k) {
      if (m >= 2 * k + 3)
        ans = 4;
    }
    else if (n == 4 * k) {
      if (m >= 2 * k + 3)
        ans = 4;
    }
    else if (n >= 2 * k + 1 && m >= 2 * k + 3) {
      if (2 * k >= k + 2)
        ans = 4;
      else if (3 * k >= k + 2)
        ans = 5;  
    }
    printf("Case #%d: %d\n", tc, ans);
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}