#include <bits/stdc++.h>

using namespace std;

vector<int> to, head, tail;

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  to.assign(n, -1);
  head.assign(m, -1);
  tail.assign(m, -1);
  for (int i = 0; i < m; ++i) {
    int l;
    scanf("%d", &l);
    while (l--) {
      int x;
      scanf("%d", &x);
      --x;
      to[x] = head[i];
      head[i] = x;
      if (tail[i] == -1)
        tail[i] = x;
    }
  }
  while (q--) {
    int ty, x, y;
    scanf("%d %d", &ty, &x);
    --x;
    if (ty == 2) {
      assert(head[x] != -1);
      head[x] = to[head[x]];
      if (head[x] == -1)
        tail[x] = -1;
    } else {
      scanf("%d", &y);
      --y;
      if (ty == 1) {
        to[x] = head[y];
        head[y] = x;
        if (tail[y] == -1)
          tail[y] = x;
      } else {
        if (tail[x] != -1) {
          to[tail[x]] = head[y];
          head[y] = head[x];
          if (tail[y] == -1)
            tail[y] = tail[x];
          tail[x] = head[x] = -1;
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (head[i] == -1) continue;
    printf("%d:", i+1);
    stack<int> st;
    int now = head[i];
    while (now != -1) {
      st.push(now);
      now = to[now];
    }
    while (!st.empty()) {
      printf(" %d", st.top() + 1);
      st.pop();
    }
    printf("\n");
  }
  return 0;
}
