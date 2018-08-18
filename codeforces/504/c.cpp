#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

bool used[N];
char s[N];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      st.push(i);
    }
    else {
      assert(!st.empty());
      int pasang = st.top();
      st.pop();
      if (k > 0) {
        k -= 2;
        used[pasang] = used[i] = 1;
      }
    }
  }
  for (int i = 0; i < n; ++i)
    if (used[i])
      printf("%c", s[i]);
  printf("\n");
  return 0;
}