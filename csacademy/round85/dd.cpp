#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];
int ans[N];
bool ada[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  stack<int> st;
  int m = 0;
  st.push(a[0]);
  ada[m] = 1;
  ans[m++] = a[0];
  for (int i = 1; i < n; ++i) {
    int now = a[i];
    while (st.top() < now) {
      int v = st.top();
      --k;
      ans[m++] = v;
      while (!st.empty() && st.top() == v) {
        st.pop();
        ++v;
      }
      st.push(v);
    }
    ada[m] = 1;
    ans[m++] = now;
    while (!st.empty() && st.top() == now) {
      st.pop();
      ++now;
    }
    st.push(now);
  }
  while (st.top() < 30) {
    int v = st.top();
    --k;
    ans[m++] = v;
    while (!st.empty() && st.top() == v) {
      st.pop();
      ++v;
    }
    st.push(v);
  }
  assert(st.size() == 1 && st.top() == 30);
  assert(k >= 0);
  stack<int> stak;
  for (int i = 0; i < m; ++i) {
    if (ada[i]) {
      printf("%d ", ans[i]);
      continue;
    }
    stak.push(ans[i]);
    while (k > 0 && !stak.empty()) {
      if (stak.top() == 0) {
        printf("0 ");
        stak.pop();
        continue;
      }
      int v = stak.top();
      stak.pop();
      --k;
      --v;
      stak.push(v);
      stak.push(v);
    }
    while (!stak.empty()) {
      printf("%d ", stak.top());
      stak.pop();
    }
  }
  printf("\n");
  return 0;
}