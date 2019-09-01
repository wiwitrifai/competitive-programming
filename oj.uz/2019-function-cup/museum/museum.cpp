#include "museum.h"
#include <bits/stdc++.h>

using namespace std;


template<typename T>
long long calc(vector<T> v) {
  sort(v.begin(), v.end());
  long long ans = 0;
  int cnt = 0;
  T last = v[0];
  for (int i = 0; i < (int)v.size(); ++i) {
    if (last != v[i]) {
      ans += 1L * cnt * (cnt - 1) / 2;
      cnt = 0;
      last = v[i];
    }
    ++cnt;
  }
  ans += 1LL * cnt * (cnt - 1) / 2;
  return ans;
}

template<typename T>
long long calc2(vector<T> A, vector<T> B) {
  vector<pair<T, T>> v(A.size());
  for (int i = 0; i < (int)v.size(); ++i)
    v[i] = {A[i], B[i]};
  return calc(v);
}

template<typename T>
long long calc3(vector<T> A, vector<T> B, vector<T> C) {
  vector<tuple<T, T, T>> v(A.size());
  for (int i = 0; i < (int)v.size(); ++i)
    v[i] = {A[i], B[i], C[i]};
  return calc(v);
}

long long CountSimilarPairs(std::vector<int> B, std::vector<int> T, std::vector<int> G) {
	return calc(B) + calc(T) + calc(G) - calc2(B, T) - calc2(B, G) - calc2(T, G) + calc3(B, T, G);
}
