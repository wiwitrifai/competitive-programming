#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 5;

int a[N];

int main() {
  int m;
  scanf("%d %d %d", a, a+1, &m);
  set<int> st;
  for (int i = 2; i < N; ++i) {
    a[i] = (a[i-1] + a[i-2]);
    if (a[i] >= m)
      a[i] -= m;
  }
  for (int i = 0; i < N; ++i)
    st.insert(a[i]);
  printf("%d\n", (int)st.size());
  return 0;
}