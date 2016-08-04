#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

long long a[N], k;
vector<pair<pair<int, int>, long long> > dp[N];
#define ff first.first
#define fs first.second
#define ss second
vector< long long > d;

long long gcd(long long x, long long y) {
  return x ? gcd(y % x, x) : y;
}
int get(long long dd) {
  return lower_bound(d.begin(), d.end(), dd) - d.begin();
}

void upd(int i, int j, pair<pair<int, int>, long long> val, int jj) {
  if (jj != j) {
    val.ss += a[i];
    val.fs++;
  }
  val.ff = jj;
  if((dp[i][j].fs == 0) || (dp[i][j].fs > val.fs) || ((dp[i][j].fs == val.fs) && dp[i][j].ss > val.ss)) {
    dp[i][j] = val;
  }
}

int main() {
  int n;
  scanf("%d%lld", &n, &k);
  for(int i = 0; i<n; i++) {
    scanf("%lld", a+i);
  }
  for(int i = 1; 1LL * i * i <= k; i++) if((k % i) == 0) {
    d.push_back(i);
    long long iv = k/i;
    if(iv != i)
      d.push_back(iv);
  }
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  for(int i= 0; i<n; i++) {
    dp[i].assign(d.size(), {{-1, 0}, 0});
    long long dd = gcd(a[i], k);
    int id = get(dd);
    dp[i][id] = {{-1, 1}, a[i]};
  }
  for(int i = 0; i<n-1; i++) {
    for(int j = 0; j<d.size(); j++) if(dp[i][j].fs > 0) {
      upd(i+1, j, dp[i][j], j);
      long long now = d[j] * gcd(a[i+1], k/d[j]);
      int nx = get(now);
      if(nx != j)
        upd(i+1, nx, dp[i][j], j);
    }
  }
  auto now = dp[n-1].back();
  if(now.fs) {
    printf("%d\n", now.fs);
    int last = d.size()-1;
    int cnt = now.fs;
    for(int i = n-1; i>=0; i--) {
      // cerr << i << " " << dp[i][last].ff << " " << last << endl;
      if(dp[i][last].ff != last) {
        printf("%d ", i+1);
        cnt--;
        if(cnt == 0)
          break;
      }
      last = dp[i][last].ff;
    }
    printf("\n");
  }
  else {
    puts("-1");
  }
  return 0;
}