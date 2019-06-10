#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int grund[N];

int main() {
  grund[2] = 1;
  for (int i = 3; i < N; ++i) {
    set<int> st;
    for (int j = 1; j < i; ++j) {
      st.insert(grund[j-1]^grund[i-j-1]);
    }
    for (int x : st)
      grund[i] += grund[i] == x;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    puts(grund[n] ? "First" : "Second");
  }
  return 0;
}
