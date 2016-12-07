#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int a[N];
bool vis[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
  }
  memset(vis, 0, sizeof vis);
  int ans = 0;
  for (int i = 1; i <= n; i++) if (!vis[i]) {
    int now = i, cnt = 0;
    while (!vis[now]) {
      vis[now] = 1;
      now = a[now];
      cnt++;
    }    
    if (now != i) {
      ans = -1;
      break;
    }
    else {
      if ((cnt & 1) == 0)
        cnt /= 2;
      if (!ans)
        ans = cnt;
      else {
        int g = gcd(cnt, ans);
        ans = ans * (cnt / g);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}