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
int len, m, k, q;
int ll[N], rr[N];
int st[N], a[N], b[N];
int sum[N];
int sp[20][N];

const int inf = 1e8;

int get(int l, int r) {
  if (l > r) return inf;
  int le = r-l+1;
  int lg = 31 - __builtin_clz(le);
  return min(sp[lg][l], sp[lg][r-(1<<lg)+1]);
}

int f(int id, int le) {
  int cur = pos[id];
  int l = 0, r = cur;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (get(mid, cur-1) >= le)
      r = mid;
    else
      l = mid+1;
  }
  int left = l;
  l = cur-1; r = n-1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (get(cur, mid) >= le)
      l = mid;
    else
      r = mid - 1;
  }
  return sum[l+2 >= n ? n : l+2]-sum[left];
}
const int MAGIC = 360;
int dp[N][MAGIC];
vector< int > id[1024][1024];

int main() {
  scanf("%d %d %d %d", &len, &m, &q, &k);
  scanf("%s", s);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", ll+i, rr+i);
    if (k < 1024)
      id[ll[i]][rr[i]].push_back(i);
  }
  int off = len + 1;
  for (int i = 0; i < q; i++) {
    st[i] = off;
    scanf("%s %d %d", s+off, a+i, b+i), off += k + 1;
  }
  n = off;
  build_sa();
  build_lcp();
  // for (int i = 0; i < n; i++)
  //   cerr << i << " " <<  s+sa[i] << " " << lcp[i] << endl;
  sum[0] = 0;
  for (int i = 0; i < n; i++)
    sum[i+1] = sum[i] + (sa[i] < len);
  sum[n+1] = sum[n];
  for (int i = 0; i < n; i++)
    sp[0][i] = lcp[i];
  for (int i = 0; i+1 < 20; i++) {
    for (int j = 0; j + (1<<(i+1))<= n; j++)
      sp[i+1][j] = min(sp[i][j], sp[i][j+(1<<i)]);
  }
  if (k < MAGIC) {
    int tmp[MAGIC];
    memset(tmp, -1, sizeof tmp);
    for (int i = 0; i < n; i++) {
      int now = -1;
      for (int j = 0; j <= k; j++) {
        dp[i][j] = now+1;
        now = max(now, tmp[j]);
        tmp[j] = now;
      }
      if (lcp[i] <= k)
        tmp[lcp[i]] = i;
    }
    for (int j = 0; j <= k; j++)
      tmp[j] = n;
    for (int i = n-1; i >= 0; i--) {
      int now = n;
      if (lcp[i] <= k)
        tmp[lcp[i]] = i;
      for (int j = 0; j <= k; j++) {
        // cerr << dp[i][j] << "-" << now << endl;
        dp[i][j] = sum[now+1] - sum[dp[i][j]];
        now = min(now, tmp[j]);
        tmp[j] = now;
      }
    }
    for (int i = 0; i < q; i++) {
      long long ans = 0;
      for (int j = 0; j < k; j++) {
        for (int z = j; z < k; z++) {
          int cnt = upper_bound(id[j][z].begin(), id[j][z].end(), b[i]) - lower_bound(id[j][z].begin(), id[j][z].end(), a[i]);
          if (cnt == 0)
            continue;
          ans += 1LL * cnt * dp[pos[st[i]+j]][z-j+1];          
        }
      }
      printf("%lld\n", ans);
    }
  }
  else if (k < 1024) {
    for (int i = 0; i < q; i++) {
      long long ans = 0;
      for (int j = 0; j < k; j++)
        for (int z = j; z < k; z++) {
          int cnt = upper_bound(id[j][z].begin(), id[j][z].end(), b[i]) - lower_bound(id[j][z].begin(), id[j][z].end(), a[i]);
          if (cnt == 0)
            continue;
          ans += 1LL * cnt * f(st[i]+j, z-j+1);
        }
      printf("%lld\n", ans);
    }
  }
  else {
    for (int i = 0; i < q; i++) {
      long long ans = 0;
      for (int j = a[i]; j <= b[i]; j++) {
        ans += f(st[i]+ll[j], rr[j]-ll[j]+1);
      } 
      printf("%lld\n", ans);
    }
  }
  return 0;
}