#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    printf("Case #%d:\n", tc);
    deque< int > dq;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      dq.push_back(i);
    if (n == 1)
      puts("");
    while (dq.size() > 1) {
      printf("%d%c", dq.front(), dq.size() == 2 ? '\n' : ' ');
      dq.pop_front();
      dq.push_back(dq.front());
      dq.pop_front();
    }
    printf("%d\n", dq.front());
  }
  return 0;
}