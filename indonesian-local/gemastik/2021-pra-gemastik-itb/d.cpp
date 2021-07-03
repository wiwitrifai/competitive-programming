#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long m_cnt[20][11][11];

long long rec(int len, int cur, int tot) {
  long long & ret = m_cnt[len][cur][tot];
  if (ret != -1)
    return ret;
  if (len == 0)
    return ret = 1;
  ret = rec(len-1, cur, tot) * cur % mod;
  if (cur < tot) {
    ret += rec(len-1, cur+1, tot) * (10 - cur);
  }
  ret %= mod;
  return ret;
}

long long m_cnt_dig[20][11][11];
long long rec_dig(int len, int cur, int tot) {
  if (cur > tot)
    return 0;
  long long & ret = m_cnt_dig[len][cur][tot];
  if (ret != -1)
    return ret;
  if (len == 0)
    return ret = 0;
  ret = (rec_dig(len-1, cur, tot) * cur + rec(len-1, cur, tot)) % mod;
  if (cur < tot) {
    ret += rec_dig(len-1, cur+1, tot) * (10 - cur);
  }
  ret %= mod;
  return ret;
}

long long calc(long long m, int ndig) {
  if (ndig == 0)
    return 0;
  ndig = min(ndig, 10);
  vector<int> digs;
  while (m) {
    digs.push_back(m % 10);
    m /= 10;
  }
  int n = digs.size();
  vector<int> cnt(10, 0);
  int ndiff = 0, sumdig = 0, sumdiff = 0;
  long long ans = 0;
  for (int i = n-1; i >= 0; --i) {
    for (int j = (i < n-1) ? 0 : 1; j < digs[i]; ++j) {
      ndiff += cnt[j] == 0;
      sumdig += j;
      if (cnt[j] == 0)
        sumdiff += j;
      ++cnt[j];
      if (ndiff <= ndig) {
        ans += rec(i, ndiff, ndig) * sumdig + sumdiff * rec_dig(i, ndiff, ndig);
        ans %= mod;
        ans += (45 - sumdiff) * rec_dig(i, ndiff+1, ndig);
        ans %= mod;
      }
      --cnt[j];
      if (cnt[j] == 0)
        sumdiff -= j;
      sumdig -= j;
      ndiff -= cnt[j] == 0;
    }
    ndiff += cnt[digs[i]] == 0;
    if (cnt[digs[i]] == 0)
      sumdiff += digs[i];
    sumdig += digs[i];
    ++cnt[digs[i]];
    if (ndiff > ndig)
      break;
  }
  for (int i = 1; i < n-1; ++i) {
    ans += 45LL * rec_dig(i, 1, ndig);
    ans += 8 * 45LL * rec_dig(i, 2, ndig);
    ans %= mod;
  }
  for (int i = 1; i < n; ++i) {
    ans += 45 * rec(i-1, 1, ndig);
    ans %= mod;
  }
  ans %= mod;
  return ans;
}

long long calc2(long long m, int ndig) {
  long long ans = 0;
  for (int i = 1; i < m; ++i) {
    int now = i;
    set<int> st;
    int sum = 0;
    while (now) {
      int d = now % 10;
      now /= 10;
      st.insert(d);
      sum += d;
    }
    if ((int)st.size() <= ndig) {
      ans += sum;
    }
  }
  return ans;
}

int main() {
  memset(m_cnt, -1, sizeof m_cnt);
  memset(m_cnt_dig, -1, sizeof m_cnt_dig);
  long long l, r;
  scanf("%lld %lld", &l, &r);
  int p, q;
  scanf("%d %d", &p, &q);
  ++r;
  --p;
  long long ans = calc(r, q) - calc(l, q) - calc(r, p) + calc(l, p);
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
