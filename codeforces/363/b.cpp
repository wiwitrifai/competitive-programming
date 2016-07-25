#include <bits/stdc++.h>

using namespace std;

const int N  = 2e6 + 5;

int n, p[N];
int vis[N];


int main() {
  scanf("%d", &n);
  int root = -1;
  for(int i = 0; i<n; i++) {
    scanf("%d", p+i);
    p[i]--;
    vis[i] = 0;
    if(p[i] == i)
      root = i;
  }
  int ans = 0;
  if(root != -1)
    vis[root] = 2;
  for(int i = 0; i<n; i++) if(vis[i] == 0) {
    int now = i;
    while(vis[now] == 0) {
      vis[now] = 1;
      now = p[now];
    }
    bool cyc = vis[now] == 1;
    now = i;
    while(vis[now] == 1) {
      vis[now] = 2;
      now = p[now];
    }
    if(cyc) {
      ans++;
      if(root == -1)
        root = now;
      p[now] = root;
    }
  }
  printf("%d\n", ans);
  for(int i = 0; i<n; i++)
    printf("%d ", p[i]+1);
  printf("\n");

  return 0;
}