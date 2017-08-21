#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;

int main() {
  int n;
  int v = 0, ov = 0, ans = 0;
  stack<int> st;
  st.push(1e9);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d", &y);
      v = y;
    }
    else if (x == 2) {
      ans += ov;
      ov = 0;
    }
    else if (x == 3) {
      scanf("%d", &y);
      st.push(y);
    }
    else if (x == 4) {
      ov = 0;
    }
    else if (x == 5)
      st.push(1e9);
    else
      ov++;
    while (!st.empty() && st.top() < v) {
      ans++;
      st.pop();
    }
  }
  printf("%d\n", ans);
  return 0;
}