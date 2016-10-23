/**
  IEEExtreme Programming Contest 10
  Problem : P = NP?
  Solver  : Luqman Arifin S
  Status  : Accepted after contest ended
*/


#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long dp[N];
char s[100];
int n;

long long find(int l, int r) {
  if (l > r) return 0;
  return dp[r] - dp[l - 1];
}

long long mini(const vector<tuple<int, int, int>>& _a, const vector<tuple<int, int, int>>& _b) {
  long long all = 0;
  for (int i = 0; i < _a.size(); i++) {
    int p, q, r;
    tie(p, q, r) = _a[i];
    all += p;
  }
  set<tuple<int, int, int>> a, b;
  for (auto it : _a) a.insert(it);
  for (auto it : _b) b.insert(it);
  
  auto it = a.begin();
  auto jt = b.begin();
  long long ret = 0;
  while (it != a.end() && jt != b.end()) {
    int p, q, r, u, v, w;
    tie(p, q, r) = *it;
    tie(u, v, w) = *jt;
    //printf("%d %d %d - %d %d %d\n", p, q, r, u, v, w);
    if (q <= u) {
      ret += find(p + 1, p + r);
      it++;
    } else if (v <= p) {
      jt++;
    } else if (u <= p && q <= v) {
      int pp = p;
      ret += find(p + 1, p + r);
      p += r;
      
      int del = min(w, max(0, pp - u - 1));
      w -= del;
      u = p;
      
      del = min(w, max(0, q - u - 1));
      u += del;
      w -= del;
      if (u + 1 == q) u = q;
      
      if (w) {
        b.insert(make_tuple(q, v, w));
      }
      it++;
      jt++;
    } else if (p <= u && v <= q) {
      int vv = v;
      v -= w;
      
      int del = min(r, max(0, u - p - 1));
      ret += find(p + 1, p + del);
      p += del;
      r -= del;
      if (p + 1 == u) p = u;
      
      del = min(r, max(0, v - u - 1));
      ret += find(u + 1, u + del);
      r -= del;
      if (r) {
        a.insert(make_tuple(vv, q, r));
      }
      it++;
      jt++; 
    } else if (p <= u) {
      int del = min(r, max(0, u - p - 1));
      ret += find(p + 1, p + del);
      r -= del;
      p += del;
      if (p + 1 == u) p = u;
      
      ret += find(u + 1, u + r);
      u += r;
      
      del = min(w, max(0, q - u - 1));
      w -= del;
      
      if (w) {
        b.insert(make_tuple(q, v, w));
      }
      it++;
      jt++;
    } else {
      int vv = v;
      int del = min(w, max(0, p - u - 1));
      w -= del;
      
      v -= w;
      
      del = min(r, max(0, v - p - 1));
      ret += find(p + 1, p + del);
      r -= del;
      
      if (r) {
        a.insert(make_tuple(vv, q, r));
      }
      it++;
      jt++;
    }
  }
  while (it != a.end()) {
    int p, q, r;
    tie(p, q, r) = *it;
    ret += find(p + 1, p + r);
    it++;
  }
  return all + ret;
}

long long maks(const vector<tuple<int, int, int>>& _a, const vector<tuple<int, int, int>>& _b, int num) {
  vector<tuple<int, int, int>> a, b;
  for (int i = 0; i < _a.size(); i++) {
    int u, v, w;
    tie(u, v, w) = _a[i];
    a.emplace_back(n + 1 - v, n + 1 - u, w);
  }
  for (int i = 0; i < _b.size(); i++) {
    int u, v, w;
    tie(u, v, w) = _b[i];
    b.emplace_back(n + 1 - v, n + 1 - u, w);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long ret = mini(a, b);
  return 1LL * num * (n + 1) - mini(a, b);
}

int main() {
  for (int i = 1; i < N; i++) dp[i] = dp[i - 1] + i;
  int u, v;
  scanf("%d %d %d", &n, &u, &v);
  int last = 0, now = 0;
  vector<tuple<int, int, int>> a, b;
  for (int i = 0; i < u; i++) {
    scanf("%s", s);
    if (s[0] == '?') {
      now++;
    } else {
      int val = atoi(s);
      a.emplace_back(last, val, now);
      now = 0;
      last = val;
    }
  }
  a.emplace_back(last, n + 1, now);
  
  last = 0; now = 0;
  for (int i = 0; i < v; i++) {
    scanf("%s", s);
    if (s[0] == '?') {
      now++;
    } else {
      int val = atoi(s);
      b.emplace_back(last, val, now);
      now = 0;
      last = val;
    }
  }
  b.emplace_back(last, n + 1, now);
  //cout << maks(a, b) << endl;
  printf("%lld %lld\n", mini(a, b), maks(a, b, u));
  printf("%lld %lld\n", mini(b, a), maks(b, a, v));
  return 0;
}