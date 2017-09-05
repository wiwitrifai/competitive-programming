#include <bits/stdc++.h>

using namespace std;

char s[10];

int main() {
  deque<char> dq;
  int q;
  scanf("%d", &q);
  while (q--) {
    int a;
    scanf("%d %s", &a, s);
    if (a)
      dq.push_back(s[0]);
    else
      dq.push_front(s[0]);
  }
  while (!dq.empty()) {
    printf("%c", dq.front());
    dq.pop_front();
  }
  printf("\n");
  return 0;
}