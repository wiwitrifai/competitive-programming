#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int n;

int grund[N];

int calc(int x) {
  int & ret = grund[x];
  if (ret != -1)
    return ret;
  set<int> st;
  st.insert(calc(x+1));
  if (x * 2 <= n)
    st.insert(calc(x * 2));
  ret = 0;
  for (int v : st)
    ret += ret == v;
  return ret;
}

int calc2(int x) {
  int b = 1;
  while (b <= x) {
    if (b & x)
      return 0;
    b <<= 2;
  }
  return 1;
}

int main() {
  for (int i = 1; i < 1024; ++i) {
    memset(grund, -1, sizeof grund);
    n = i;
    grund[i] = 0;
    assert(calc(1) == calc2(i));
    if (calc(1))
      cerr << i << " " << calc(1) << endl;
  }
  return 0;
}
