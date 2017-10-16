#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

set<int> st;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    st.insert(i);
  printf("%d", 1);
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    st.erase(p);
    int last = 0;
    if (!st.empty())
      last = *(--st.end());
    printf(" %d", i-(n-last) + 1);
  }
  printf("\n");
  return 0;
}