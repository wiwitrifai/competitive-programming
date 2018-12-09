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

const long double PI = acos(-1);


int main() {
  open_file("baklava.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    double angle = PI / n;
    double p = cos(angle);
    p = 1 - p * p;
    double ans = 10000 / p;
    printf("%.5lf\n", ans);
  }
  close_file();
  return 0;
}