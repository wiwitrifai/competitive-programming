#include <bits/stdc++.h>

using namespace std;

char buffer[505];

int main() {
  int n;
  scanf("%d", &n);
  set<int> st;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    int len = strlen(buffer);
    if (len > 8) continue;
    int x = stoi(buffer);
    st.insert(x);
  }
  int ans = 0;
  while (st.count(ans)) ++ans;
  printf("%d\n", ans);
  return 0;
}
