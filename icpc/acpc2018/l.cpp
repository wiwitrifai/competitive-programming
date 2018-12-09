#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

const int N = 1e5 + 5;

int main() {
  open_file("looking.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      ans |= a;
    }
    printf("%d\n", ans);
  }
  close_file();
  return 0;
}