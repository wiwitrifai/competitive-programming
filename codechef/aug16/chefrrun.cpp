#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], vis[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
      scanf("%d", a+i);
      vis[i] = 0;
    }
    int ans = 0;
    for(int i = 0; i<n; i++) if(vis[i] == 0) {
      int now = i;
      while(vis[now] == 0) {
        vis[now] = 1;
        now = (now + a[now]+1) % n;
      }
      while(vis[now] == 1) {
        vis[now] = 2;
        ans++;
        now = (now + a[now] + 1) % n;
      }
      now = i;
      while(vis[now] != 2) {
        vis[now] = 2;
        now = (now + a[now] + 1) % n;
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}