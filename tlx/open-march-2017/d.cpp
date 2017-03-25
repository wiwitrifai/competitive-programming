#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int x[N], y[N];

long long dist2(int a, int b) {
  long long dx = x[a] - x[b], dy = y[a] - y[b];
  return dx * dx + dy * dy;
}

int main() {
  int q;
  scanf("%d", &q);
  int n = 0;
  while (q--) {
    int t, a, b;
    scanf("%d %d %d", &t, &a, &b);
    if (t == 1) {
      x[n] = a;
      y[n] = b;
      n++;
    }
    else {
      int ans = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
          for (int k = j + 1; k < n; k++) {
            long long v[] = {dist2(i, j), dist2(i, k), dist2(j, k)};
            sort(v, v+3);
            if (v[2] == v[1] + v[0]) {
              if (((a % v[1]) == 0 && (b % v[0]) == 0) || ((b % v[1]) == 0 && (a % v[0]) == 0))
                ans++;
            }
          }
        }
      }
      printf("%d\n", ans);
    }
  } 

  return 0;
}