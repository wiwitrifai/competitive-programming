#include <bits/stdc++.h>

using namespace std;

// suffix array
const int N = 1e5 + 5;
const int LN = 18;
const int mod = 1e9 + 7;
const int base = 1e5 + 1;

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
int pal[N + N], sparse[LN][N];

int get(int l, int r) {
  int len = r-l+1;
  int ln = 31 - __builtin_clz(len);
  // assert(len >= (1<<ln) && len < (1<<(ln+1)));
  int a = sparse[ln][l], b = sparse[ln][r-(1<<ln)+1];
  return lcp[a] < lcp[b] ? a : b;
}

long long ans[N];
pair<long long, int> que[N];
long long sum[N];
long long inv[N];

long long powmod(long long b, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}
long long calc(int l, int r) {
  long long ret = (sum[r] - sum[l]) % mod;
  ret = (ret * inv[l]) % mod;
  if (ret < 0)
    ret += mod;
  return ret;
}
int p[2][N];

int main() {
  int q;
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  for (int i = 0; i < q; i++) {
    long long k;
    scanf("%lld", &k);
    que[i] = {k, i};
  }
  sum[0] = 0;
  long long mul = 1;
  for (int i = 0; i < n; i++) {
    sum[i+1] = (sum[i] + mul * s[i]) % mod;
    mul = (mul * base) % mod;
    inv[i] = powmod(base, mod-1-i);
  }

  for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
      for(int i=0;i<n;i++)
      {
          if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
          int L=i-p[z][i], R=i+p[z][i]-!z;
          while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
          if(R>r) l=L,r=R;
      }
  for (int i = 0; i < n; i++) {
    pal[i + i] = p[0][i] * 2;
    pal[i + i + 1] = p[1][i] * 2 + 1;
  }
  build_sa();
  build_lcp();
  for (int i = 0; i < n - 1; i++) {
    sparse[0][i] = i;
  }
  for (int i = 0; i < LN; i++) {
    for (int j = 0; j + (1<<(i+1)) <= n-1; j++) {
      int a = sparse[i][j], b = sparse[i][j+(1<<i)];
      sparse[i+1][j] = lcp[a] < lcp[b] ? a : b;
    }
  }
  sort(que, que + q);
  stack < int > st;
  st.push(n-1);
  int id = 0, len = 0;
  long long kl = 0;
  for (int i = 0; i < n; i++) {
    // cerr << i  << " : " << " " << s + sa[i]<< endl;
    while (sa[i] + len + 1 <= n) {
      len++;
      int r = st.top();
      while (i < r && lcp[get(i, r-1)] < len)
        r = get(i, r-1);
      // cerr << len << " " << r << endl;
      st.push(r);
      if (pal[sa[i] + sa[i] + len] >= len) {
        kl += r - i + 1;
        long long val = calc(sa[i], sa[i]+len);
        while (id < q && que[id].first <= kl) {
          // cerr << que[id].second << " = " << sa[i] << " " << len << endl;
          ans[que[id].second] = val;
          id++;
        }
      }
    }
    while (len > lcp[i]) {
      len--;
      st.pop();
    }
  }
  while (id < q) {
    ans[que[id++].second] = -1;
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}