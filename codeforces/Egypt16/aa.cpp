#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int grund[N];

int main() {
  int b, c;
  scanf("%d %d", &b, &c);
  grund[0] = 0;
  for (int i = 1; i <= c; i++) {
    set < int > st;
    for (int j = 1; j <= i; j *= b) {
      st.insert(grund[i-j]);
    }
    grund[i] = 0;
    for (int u : st) {
      grund[i] += (u == grund[i]);
    }
    printf("%d\n", grund[i]);
  }
  return 0;
}