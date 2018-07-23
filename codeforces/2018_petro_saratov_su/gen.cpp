#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int n = 1e5, m = n;
  vector<string> st;
  int now = 1;
  while (m > 0) {
    int len = rand() % m;
    ++len;
    len = min(max(len, now), now);
    now = min(now+1, 156);
    len = min(len, m);
    string cur(len, ' ');
    for (int i = 0; i < len; ++i)
      cur[i] = 'a' + (rand() % 26);
    st.push_back(cur);
    m -= len;
  }
  printf("%d %d\n", n, st.size());
  for (int i = 0; i < n; ++i) {
    printf("%c", (rand() % 26) + 'a');
  }
  printf("\n");
  for (int i = 0; i < st.size(); ++i) {
    printf("%s\n", st[i].c_str());
  }
  return 0;
}
