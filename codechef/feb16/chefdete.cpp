#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int deg[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    deg[x]++;
  }
  for(int i = 0; i<=n; i++) if(deg[i] == 0) {
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}