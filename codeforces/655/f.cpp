#include <bits/stdc++.h>

using namespace std;

pair<int, int> ask(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int x, f;
  scanf("%d %d", &x, &f);
  return {x, f};
}


int main() {
  int n;
  scanf("%d", &n);
  vector<int> who(n+1);
  deque<pair<int, int>> cand;
  int now = 1;
  while (now <= n) {
    while (now <= n && who[now]) ++now;
    if (now > n)
      break;
    int cur = ask(now, now).first;
    while (!cand.empty()) {
      auto it = cand.front();
      if (it.first <= who[now-1]) {
        cand.pop_front();
      } else {
        break;
      }
    }
    int size = n-now + 1, nxt = -1;
    if (!cand.empty()) {
      nxt = cand.front().first;
      size = cand.front().second;
    }
    while (cand.empty() || (cand.front().first != cur)) {
      auto res = ask(now, now + size - 1);
      if (res.first == nxt) {
        int pos = now + size - res.second;
        for (int j = pos; j < pos + size; ++j)
          who[j] = nxt;
        size -= res.second;
      } else {
        cand.push_front(res);
        nxt = res.first;
        size = res.second;
      }
    }
    for (int i = 0; i < cand.front().second; ++i)
      who[now + i] = cur;
    cand.pop_front();
  }
  printf("!");
  for (int i = 1; i <= n; ++i)
    printf(" %d", who[i]);
  printf("\n");
  fflush(stdout);
  return 0;
}
