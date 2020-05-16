#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
const int N = 1e5 + 5, M = 1e9;
const long long inf = 1e18;

bool flag[N];

int cntrask = 0;

vector<pair<int, int>> ask(long long q, vector<int> &prim) {
  ++cntrask;
  printf("? %lld\n", q);
  fflush(stdout);
  long long ret;
  scanf("%lld", &ret);
  vector<pair<int, int>> fact;
  for (int p : prim) {
    if (ret % p) continue;
    int cnt = 0;
    while ((ret % p) == 0) {
      ++cnt;
      ret /= p;
    }
    fact.emplace_back(p, cnt);
  }
  return fact;
}

int main() {
  for (int i = 2; i < N; ++i) {
    if (flag[i]) continue;
    primes.push_back(i);
    for (int j = i+i; j < N; j += i)
      flag[j] = true;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    cntrask = 0;
    int j = 0;
    map<int, int> fact;
    vector<int> vp;
    long long cur = 1;
    for (int i = 0; i < 17; ++i) {
      long long now = 1;
      vector<int> cand;
      while (j < (int)primes.size() && (((inf / now >= primes[j]) && primes[j] * now <= inf))) {
        now *= primes[j];
        cand.push_back(primes[j]);
        ++j;
      }
      auto res = ask(now, cand);
      for (auto it : res) {
        fact[it.first] = it.second;
        cur *= it.first;
        vp.push_back(it.first);
      }
    }
    for (int i = 0; cntrask < 22;) {
      long long now = 1;
      vector<int> cand;
      int batas = 1;
      while (i < (int)vp.size()) {
        int cnt = 1;
        long long tmp = cur, pp = vp[i];
        while (tmp * vp[i] <= M) {
          tmp *= vp[i];
          ++cnt;
          pp *= vp[i];
        }
        if ((pp <= (inf / now)) && (pp * now <= inf)) {
          now *= pp;
          cand.push_back(vp[i]);
          batas = max(batas, vp[i]);
          ++i;
        }
        else
          break;
      }
      while (j < (int)primes.size() && ((inf / now >= primes[j]) && primes[j] * now <= inf)) {
        now *= primes[j];
        cand.push_back(primes[j]);
        ++j;
      }
      auto res = ask(now, cand);
      for (auto it : res) {
        if (it.first > batas)
          vp.push_back(it.first);
        else {
          for (int k = fact[it.first]; k < it.second; ++k)
            cur *= it.first;
        }
        fact[it.first] = max(it.second, fact[it.first]);
      }
    }
    long long ans = 1;
    for (auto it : fact) {
      ans *= it.second + 1;
    }
    ans = max(ans+7, ans*2);
    printf("! %lld\n", ans);
    fflush(stdout);
  }
  return 0;
}
