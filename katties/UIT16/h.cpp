#include <bits/stdc++.h>

using namespace std;

int n, c;
int w[1005];

int main() {
  scanf("%d%d", &n, &c);
  for(int i = 0; i<n; i++) {
    scanf("%d", w+i);
  }
  int ans = 0;
  for(int i = 0; i<n; i++) {
    int cur = 0, now = 0;
    for(int j = i; j<n; j++) {
      if(cur + w[j] <= c) {
        cur += w[j];
        now++;
      }
    }
    ans = max(ans, now);
  }
  printf("%d\n", ans);
  return 0;
}