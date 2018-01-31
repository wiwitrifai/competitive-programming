#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int grund[N];

int main() {
  for (int i = 0; i < 100; ++i) {
    set<int> st;
    for (int j = 0; (1 << j) <= i; ++j) if (i & (1 << j)) {
      st.insert(grund[i ^ ((1 << (j+1)) - 1)]);
    }
    grund[i] = 0;
    for (int x : st)
      grund[i] += x ==grund[i];
    cout << i << " " << grund[i] << endl;      
  }
  return 0;
}