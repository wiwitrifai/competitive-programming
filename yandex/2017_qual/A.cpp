#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int pos[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    pos[x] = i;
  }
  int ans = 1;
  for (int i = 1; i < n; i++)
    ans += pos[i] > pos[i+1];
  printf("%d\n", ans);
  return 0;
}