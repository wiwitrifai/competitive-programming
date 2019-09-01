#include "unique.h"
#include <bits/stdc++.h>

using namespace std;

std::vector<int> PickUnique(int N) {
  vector<int> ans(N, 0);
  vector<int> left(N, 1), right(N, 1);
  for (int i = 1; i < N; ++i)
    left[i] = UniqueCount(0, i);
  for (int i = 0; i + 1 < N; ++i)
    right[i] = UniqueCount(i, N-1);
  for (int i = 0; i < N; ++i) {
    if (i + 1 < N && right[i] <= right[i+1])
        continue;
    if (i > 0 && left[i] <= left[i-1])
        continue;
    ans[i] = 1;
  }
	return ans;
}
