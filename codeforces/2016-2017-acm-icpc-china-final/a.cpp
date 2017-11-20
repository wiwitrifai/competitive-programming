#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
int pref[N + 5];

int main() {
  pref[0] = 0;
  int now = 1;
  for(int i = 1;i <= N; ++i) {
    now <<= 1;
    now %= 7;
    pref[i] = pref[i - 1];
    if(now == 1) pref[i]++;
  }
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; ++tc){
    int x;
    scanf("%d", &x);
    printf("Case #%d: %d\n", tc, pref[x]);
  }
  return 0;
}