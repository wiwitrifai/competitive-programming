#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

pair<int, int> x[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    x[i] = {a, b};
  }
  sort(x, x+n);
  for (int i = 0; i+1 < n; ++i) {
    
  }

  return 0;
}