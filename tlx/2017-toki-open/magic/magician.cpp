#include "magician.h"

#include <bits/stdc++.h>

using namespace std;

int rev[1 << 13];

void initMagician(int N, int K) {
  memset(rev, -1, sizeof rev);
  set< int > st;
  for (int i = 0; i < (1<<N); i++) if (__builtin_popcount(i) == K) {
    int val = -1;
    for (int j = 0; j < N; j++) if ((i & (1<<j)) == 0) {
      int now = i | (1<<j);
      if (st.count(now)) continue;
      val = now;
      break;
    }
    assert (val != -1);
    st.insert(val);
    rev[val] = i;
  }
}

std::vector<int> findOriginalCards(std::vector<int> cards) {
  vector< int > ans;
  int mask = 0;
  for (int v : cards)
    mask |= (1<<(v-1));
  int cur = rev[mask], v = 1;
  while (cur) {
    if (cur & 1)
      ans.push_back(v);
    v++, cur >>= 1;
  }
  return ans;
}
