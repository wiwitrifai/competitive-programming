#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, ta, b, tb, h, m;
  scanf("%d %d", &a, &ta);
  scanf("%d %d", &b, &tb);
  scanf("%d:%d", &h, &m);
  int st = h * 60 + m;
  int cnt = 0;
  int fin = st + ta;
  int ans = 0;
  for(int i = 5 * 60; i<24 * 60; i += b) {
    if(i < fin && i + tb > st)
      ans++;
  }
  printf("%d\n", ans);
  
  return 0;
}