#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];
char last[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  char now = s[n-1];
  for (int i = n-1; i >= 0; i--) {
    now = min(s[i], now);
    last[i] = now;
  }
  int i = 0;
  stack< char > st;
  for (int it = 0; it < n; it++) {
    if (i < n) {
      bool ok = 0;
      while (st.empty() || st.top() > last[i]) {
        if (last[i] == s[i]) {
          printf("%c", s[i]);
          ok = 1;
          i++;
          break;
        }
        st.push(s[i]);
        i++;
      }
      if (!ok) {
        printf("%c", st.top());
        st.pop();
      }
    }
    else {
      printf("%c", st.top());
      st.pop();
    }
  }
  printf("\n");
  return 0;
}