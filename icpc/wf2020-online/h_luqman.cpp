/**
 *  Coded by Luqman
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

char s[N];
int c[N];

int solve(int l, int r) {
  if (l + 1 == r) return 0;
  if (c[l] == r) return solve(l + 1, r - 1);
  int i = l;
  vector<int> a;
  // printf("solve %d %d\n", l, r);
  while (i <= r) {
    // printf("start at %d\n", i);
    assert(s[i] == '(');
    int until = c[i];
    a.push_back(solve(i, until));
    i = until + 3;
  }
  for (int i = (int) a.size() - 1; i >= 1; i--) {
    a[i-1] = max(a[i-1] + 1, a[i]);
  }
  return a[0];
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int now = 0;
  vector<int> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      now++;
      st.push_back(i);
    } else if (s[i] == ')') {
      c[st.back()] = i;
      st.pop_back();
    }
  }
  cout << solve(0, n - 1) << endl;
  return 0;
}
