#include <bits/stdc++.h>

using namespace std;

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d:\n", tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}