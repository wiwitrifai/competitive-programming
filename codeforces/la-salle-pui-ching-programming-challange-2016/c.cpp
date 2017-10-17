#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
long long p[N], q[N], pp[N];
int pre[N], cnt[N];
long long n, r, k;
int z = 0;

long long get(int mask) {
  long long ret = 1;
  for (int i = 0; i < z; i++)
    if (mask & (1 << i))
      ret *= pp[i];
  if (ret <= r)
    return ret;
  return -1;
}

set<long long> st;

void generate(int id, long long now) {
  if (st.size() >= n) return;
  if (now > r) return;
  if (id == z) {
    st.insert((int)now);
    return;
  }
  for (int i = 0; i <= q[id]; i++) {
    generate(id+1, now);
    now *= p[id];
  }
}

int main() {
  scanf("%lld %lld %lld", &n, &r, &k);
  z = 0;
  for (long long i = 2; 1LL * i * i <= k; i++) if ((k % i) == 0) {
    p[z] = i;
    pp[z] = 1;
    q[z] = 0;
    while ((k % i) == 0) {
      k /= i;
      q[z]++;
      pp[z] *= i;
    }
    z++;
  }
  if (k > 1) {
    p[z] = k;
    pp[z] = k;
    q[z] = 1;
    z++;
  }
  int zz = 1 << z;
  fill(cnt, cnt + zz, N);
  fill(pre, pre + zz, -1);
  cnt[0] = 0;
  pre[0] = 0;
  for (int mask = 0; mask < zz; mask++) {
    if (get(mask) != -1) {
      pre[mask] = 0;
      cnt[mask] = 1;
    }
    for (int bef = mask; bef > 0; bef = (bef - 1) & mask) {
      if (pre[bef] == -1) continue;
      int now = mask ^ bef;
      if (get(now) != -1) {
        if (cnt[mask] > cnt[bef] + 1) {
          cnt[mask] = cnt[bef] + 1;
          pre[mask] = bef;
        }
      }
    }
  }
  st.clear();
  int now = zz-1;
  if (pre[now] == -1) {
    puts("-1");
    return 0;
  }
  while (now > 0) {
    long long x = get(now ^ pre[now]);
    assert(x != -1);
    st.insert(x);
    now = pre[now];
  }
  generate(0, 1);
  // cerr << st.size() << endl;
  if (st.size() != n)
    puts("-1");
  else {
    for (long long x : st)
      printf("%lld ", x);
    printf("\n");
  }
  return 0;
}