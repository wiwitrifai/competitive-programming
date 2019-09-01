#include "hiccup.h"

#include <bits/stdc++.h>

using namespace std;

bool can(string & S, int & it, int x) {
  int cnt = 0, need = 0;
  while (it < S.size()) {
    if (cnt > 0 && need == 0) {
      --cnt;
      need = x;
    }
    char ch = S[it++];
    if (ch == '!') {
      if (need > 0) {
        --need;
      }
    }
    else  if (ch == 'H') {
      bool res = can(S, it, x);
      if (!res)
        return false;
      ++cnt;
    }
    else {
      return cnt <= 0 && need <= 0;
    }
  }
  return cnt <= 0 && need <= 0;
}

int HicCup(std::string S) {
	int N = S.size();
  int open = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'H')
      ++open;
    else if (S[i] == 'C')
      --open;
    if (open < 0)
      return -1;
  }
  if (open != 0)
    return -1;
  if (S[0] == '!')
    return -1;
  for (int i = 0; i + 1 < N; ++i) {
    if (S[i] == 'H' && S[i+1] == '!')
      return -1;
  }
  int low = 0, hi = N;
  while (low < hi) {
    int mid = (low + hi + 1) >> 1;
    int it = 0;
    if (can(S, it, mid))
      low = mid;
    else
      hi = mid-1;
  }
	return low;
}
