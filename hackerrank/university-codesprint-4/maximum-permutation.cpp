#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LG = 20;

// suffix array
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

int sp[LG][N];

int get(int l, int r) {
  int len = r - l;
  int lg = 31 - __builtin_clz(len);
  return min(sp[lg][l], sp[lg][r-(1<<lg)]);
}
char p[N];
int cnt[26];
bool cek[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", p, s);
    n = strlen(s);
    int k = strlen(p);
    build_sa();
    build_lcp();
    for (int i = 0; i + 1 < n; ++i)
      sp[0][i] = lcp[i];
    for (int i = 0; i + 1 < LG; ++i) {
      for (int j = 0; j + (1 << (i+1)) < n; ++j) {
        sp[i+1][j] = min(sp[i][j], sp[i][j+(1<<i)]);
      }
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < k; ++i) {
      ++cnt[p[i]-'a'];
    }
    memset(cek, 0, sizeof cek);
    for (int i = 0; i < n; ++i) {
      --cnt[s[i]-'a'];
      if (i >= k)
        ++cnt[s[i-k]-'a'];
      if (i+1 >= k) {
        bool ok = 1;
        for (int j = 0; j < 26; ++j)
          ok &= cnt[j] == 0;
        cek[i-k+1] = ok;
      }
    }
    int ans = -1, best = 0;
    for (int i = 0; i < n; ++i) {
      if (cek[sa[i]]) {
        int j = i+1; 
        while (j < n && get(i, j) >= k) ++j;
        if (j-i > best)
          ans = sa[i], best = j-i;
        i = max(j-1, i);
      }
    }
    if (ans != -1) {
      s[ans+k] = 0;
      printf("%s\n", s+ans);
    }
    else
      puts("-1");
  }
  return 0;
}