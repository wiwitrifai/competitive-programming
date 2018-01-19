#include <bits/stdc++.h>

using namespace std;

// suffix array
const int N = 3e5 + 5;
char s[N];
int sa[N], pos[N], lcp[N], tmp[N], gap, n;

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < n && b < n) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  for(int i = 0; i<n; i++)
    sa[i] = i, pos[i] = s[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + n, cmp_sa);
    for(int i = 1; i<n; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<n; i++) pos[sa[i]] = tmp[i];
    if(tmp[n-1] == n-1) break;
  }
}

void build_lcp() {
  for(int i = 0, k = 0; i<n; i++) if(pos[i] - n + 1) {
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k]; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
}

vector<long long> cnt;
vector<int> idx, lo, hi, w;
int sp[20][N];

long long calc(int x) {
  return 1LL * x * (x+1) / 2;
}

int get(int l, int r) {
  int len = r - l + 1;
  int lg = 31 - __builtin_clz(len);
  return min(sp[lg][l], sp[lg][r-(1 << lg) + 1]);
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  build_sa();
  build_lcp();
  for (int i = 0; i < n-1; ++i)
    sp[0][i] = lcp[i];
  for (int i = 0; i + 1 < 20; ++i) {
    for (int j = 0; j + (1 << (i+1)) < n; ++j) {
      sp[i+1][j] = min(sp[i][j], sp[i][j+(1 << i)]);
    }
  }
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    int from = i ? lcp[i-1] : 0, to = n-sa[i];
    int l = i, r = n-1;
    while (from < to) {
      l = i;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (get(i, mid) <= from)
          r = mid;
        else
          l = mid + 1;
      }
      int til = l <= i ? to : get(i, l-1);
      int len = l - i + 1;
      cur += 1LL * len * (calc(til) - calc(from));
      w.push_back(len);
      lo.push_back(from);
      hi.push_back(til);
      cnt.push_back(cur);
      idx.push_back(i);
      from = til;
    }
  }
  int q;
  scanf("%d", &q);
  long long g = 0;
  while (q--) {
    long long p, m;
    scanf("%lld %lld", &p, &m);
    long long k = (p * g) % m;;
    int id = upper_bound(cnt.begin(), cnt.end(), k) - cnt.begin();
    k -= id ? cnt[id-1] : 0;
    int from = lo[id], to = hi[id];
    int len = w[id];
    id = idx[id];
    int l = from, r = to;
    while (l < r) {
      int mid = (l + r) >> 1;
      if ((calc(mid) - calc(from)) * len <= k)
        l = mid + 1;
      else
        r = mid;
    }
    k -= (calc(l-1) - calc(from)) * len;
    k %= l;
    char ans = s[sa[id] + k];
    printf("%c\n", ans);
    g += ans;
  }
  return 0;
}