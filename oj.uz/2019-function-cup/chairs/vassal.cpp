#include "vassal.h"

#include <bits/stdc++.h>

using namespace std;


set<pair<int, int>> st;
void Init(long long B, std::vector<int> C){
	int N = C.size();
  for (int i = 0; i < N; ++i) {
    st.insert(make_pair(C[i], i));
  }
}

int Maid(int W){
  auto it = st.lower_bound(make_pair(W, -1));
  if (it == st.end())
  	return -1;
  int ret = it->second;
  st.erase(it);
  return ret;
}
