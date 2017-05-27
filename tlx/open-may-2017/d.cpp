#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t[N], b[N], n;

double E[N];

int main() {
  scanf("%d", &n);
  double ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", t+i, b+i);
  }
  E[n] = 0;
  for (int i = n-1; i >= 0; i--) {
    E[i] = 0.5 * E[i+1];
    if (b[i])
      E[i] += 0.5 * t[i];
    else
      E[i] += 0.5 * (E[i+1] + t[i]);
  }
  printf("%.10lf\n", E[0]);
  return 0;
}