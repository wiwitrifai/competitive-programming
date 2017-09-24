#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

int s[N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int e, n;
    scanf("%d %d", &e, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", s+i);
    }
    sort(s, s+n);
    int h = 0;
    for (int i = 0, j = n-1; i <= j; i++) {
      if (s[i] < e) {
        e -= s[i];
        h++;
      }
      else if (h > 0 && i < j) {
        e += s[j]-s[i];
        j--;
      }
    }
    printf("Case #%d: %d\n", tc, h);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}