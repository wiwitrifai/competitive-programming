#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], ans[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  deque<pair<int, int >> dq;
  while(m--) {
    int t, r;
    scanf("%d%d", &t, &r);
    while(!dq.empty()) {
      int last = dq.back().first;
      if(last <= r)
        dq.pop_back();
      else
        break;
    }
    dq.push_back({r, t});
  }
  dq.push_back({0, 1});
  for(int i = 0; i<n; i++)
    ans[i] = a[i];
  int x = 0, y = dq.front().first - 1;
  sort(a, a+y+1);
  while(dq.size() > 1) {
    int r = dq.front().first;
    int t = dq.front().second;
    dq.pop_front();
    int to = dq.front().first;
    if(t == 1)
      for(int i = r-1; i>=to; i--)
        ans[i] = a[y--];
    else
      for(int i = r-1; i>=to; i--)
        ans[i] = a[x++];
  }
  for(int i = 0; i<n; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}