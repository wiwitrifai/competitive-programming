#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, inf = 1e9;
char s[N];
int sa[N], pos[N], lcp[N], tmp[N], gap, len;

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < len && b < len) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  for(int i = 0; i<len; i++)
    sa[i] = i, pos[i] = s[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + len, cmp_sa);
    for(int i = 1; i<len; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<len; i++) pos[sa[i]] = tmp[i];
    if(tmp[len-1] == len-1) break;
  }
}

void build_lcp() {
  for(int i = 0, k = 0; i<len; i++) if(pos[i] - len + 1) {
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k]; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
}

int n;
int st[N], slen[N];
const int LN = 20;
int sp[LN][N];

int get(int l, int r) {
  if (l >= r) return inf;
  int len = r-l;
  int lg = 31 - __builtin_clz(len);
  return min(sp[lg][l], sp[lg][r-(1<<lg)]);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    int n;
    scanf("%d", &n);
    int now = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", s+now);
      st[i] = now;
      slen[i] = strlen(s+now);
      now += slen[i];
      s[now++] = '#';
    }
    len = now;
    build_sa();
    build_lcp();
    for (int i = 0; i < len; i++) {
      sp[0][i] = lcp[i];
    }
    for (int i = 0; i + 1 < LN; i++) {
      for (int j = 0; j + (1 << (i+1)) <= len; j++)
        sp[i+1][j] = min(sp[i][j], sp[i][j+(1<<i)]);
    }
    int ansl = slen[0] + 1, anst = -1;
    for (int i = 0, l = 0, r = 1; i < len; i++) {
      r = max(i+1, r);
      while (r < len && sa[r] < slen[0]) r++;
      if (sa[i] < slen[0]) {
        int now = sa[i];
        int lnow = slen[0] - now;
        int cur = 0;
        if (r < len) {
          cur = max(get(i, r)+1, cur);
        }
        if (l < i) {
          cur = max(get(l, i)+1, cur);
        }
        if (cur <= lnow && cur < ansl) {
          anst = now;
          ansl = cur;
        }
      }
      else {
        l = i;
      }
    }
    if (anst == -1)
      puts("Impossible");
    else {
      s[anst + ansl] = 0;
      printf("%s\n", s+anst);
    }
  }
  return 0;
}