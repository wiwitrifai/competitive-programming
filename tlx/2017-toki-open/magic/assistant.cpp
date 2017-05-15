#include "assistant.h"

#include <bits/stdc++.h>

using namespace std;

int to[1 << 13];

void initAssistant(int N, int K) {
  memset(to, -1, sizeof to);
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
    to[i] = val;
  }
}

int giveClue(std::vector<int> cards) {
  int mask = 0;
  for (int v : cards)
    mask |= (1<<(v-1));
  int cur = to[mask] ^ mask, ret = 0;
  while (cur) ret++, cur >>= 1;
  return ret;
}
