#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int ans[N];

int main() {
  memset(ans, -1, sizeof ans);
  int p;
  scanf("%d", &p);
  for (int i = 0; i < p; i++) {
    long long r = (1LL * i * i) % p;
    ans[r] = i; 
  }
  for (int i = 0; i < p; i++)
    printf("%d ", ans[i]);
  printf("\n");
}