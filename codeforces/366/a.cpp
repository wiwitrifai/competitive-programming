#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;

int n, q;
bool ok[N];
int a[N];
stack< int > id[N];
queue< int > all;

int main() {
  scanf("%d%d", &n, &q);
  int cnt = 0;
  int now = 1;
  for(int i = 1; i<=q; i++) {
    int ty, x;
    scanf("%d%d", &ty, &x);
    if(ty == 1) {
      id[x].push(now);
      all.push(now);
      ok[now] = true;
      a[now] = x;
      now++;
      cnt++;
    }
    else if(ty == 2) {
      while(!id[x].empty()) {
        if(ok[id[x].top()]) {
          ok[id[x].top()] = false;
          cnt--;
        }
        id[x].pop();
      }
    }
    else {
      while(!all.empty()) {
        int top = all.front();
        if(top > x)
          break;
        if(ok[top]) {
          ok[top] = false;
          cnt--;
        }
        all.pop();
      }
    }
    printf("%d\n", cnt);
  }
  
  return 0;
}