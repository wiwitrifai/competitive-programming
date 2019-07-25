#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long upper = 1e9;

vector<int> prime;
bool isp[N];

pair<long long, long long> cand[N];
vector<long long> fact;

int main() {
  for (int i = 2; i < N; ++i) {
    if (isp[i]) continue;
    prime.push_back(i);
    for (int j = i+i; j < N; j += i)
      isp[j] = 1;
  }
  long long s;
  cin >> s;
  for (int i = 0; i < N; ++i) {
    cand[i] = make_pair(s+i, 1);
  }
  for (int p : prime) {
    long long cur = (s / p) * p;
    while (cur < s) cur += p;
    while (cur < s + N) {
      int now = cur - s;
      long long v = cand[now].first, u = cand[now].second;
      while ((v % p) == 0) {
        v /= p;
        u *= p;
        if (v <= upper && u <= upper) {
          printf("0 0 %lld %lld %lld %lld\n", v, (long long)now, 1LL, u);
          return 0;
        }
      }
      cand[now] = {v, u};
      cur += p;
    }
  }
  for (int i = 0; i < N; ++i) {
    if (cand[i].first <= cand[i].second) {
      fact.clear();
      fact.push_back(1);
      long long cur = cand[i].second * cand[i].first;
      for (int p : prime) {
        int sz = fact.size();00
        long long pp = 1;
        while ((cur % p) == 0) {
          pp *= p;
          for (int j = 0; j < sz; ++j)
            fact.push_back(fact[j] * pp);
          cur /= p;
        }
      }
      if (cur > 1) {
        int sz = fact.size();
        for (int j = 0; j < sz; ++j)
          fact.push_back(fact[j] * cur);
      }
      cur = cand[i].second * cand[i].first;
      for (long long u : fact) {
        long long v = cur / u;
        if (v <= upper && u <= upper) {
          printf("0 0 %lld %lld %lld %lld\n", v, (long long)i, 1LL, u);
          return 0;
        }
      }
    }
  }
  cout << " WA " << endl;
  return 0;
}
