#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int x[N];
int n, a, b;

int can(int d) {
  set<int> st;
  st.insert(a);
  for (int i = 1; i <= n; i++) {
    int low = x[i]-d, up = x[i]+d;
    set<int>::iterator it;
    if (abs(x[i-1]-x[i]) <= d)
      st.insert(x[i-1]);
    while (!st.empty() && *(it = st.begin()) < low) st.erase(it);
    while (!st.empty() && *(it = --st.end()) > up) st.erase(it);
    if (st.empty()) return false;
  }
  return true;
}

int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; i++)
    scanf("%d", x+i);
  x[0] = b;
  int l = abs(a-b), r = 1e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}