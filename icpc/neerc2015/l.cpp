#include <bits/stdc++.h>

using namespace std;

const string NAME = "landscape";

const int N = 1e5 + 5;
const int inf = 2e9;

struct sparse {
  sparse(vector<int> a) : a(a) {
    num.resize(a.size());
    for (int i = 0; i < a.size(); i++) {
      num[i].assign(20, inf);
      num[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= a.size(); j++) {
      for (int i = 0; i + (1 << j) <= a.size(); i++) {
        num[i][j] = max(num[i][j-1], num[i+(1<<(j-1))][j-1]);
      }
    }
  }
  int find(int l, int r) {
    int g = __builtin_clz(r - l + 1) ^ 31;
    return max(num[l][g], num[r-(1<<g)+1][g]);
  }
  
  vector<vector<int>> num;
  vector<int> a;
};

long long s[N], pol[N];

long long find(int l, int r) {
  return s[r] - (l? s[l - 1] : 0);
}

long long sum(long long n) {
  return 1LL * n * (n + 1) / 2;
}

long long sum(long long l, long long r) {
  return sum(r) - sum(l - 1);
}

int main() {
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
  
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  vector<int> a, lef, rig;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    a.push_back(v);
    lef.push_back(v + n - i);
    rig.push_back(v + i);
    ans = max(ans, (long long) v);
    s[i] = v;
    if (i) s[i] += s[i - 1];
  }
  sparse slef(lef);
  sparse srig(rig);
  
  //for (int i = 0; i < n; i++) printf("%d ", slef.find(i, n - 1)); printf("\n");
  fill(pol, pol + N, 1e18);
  long long now = -1e9;
  for (int i = 0; i < n; i++) {
    now = max(now + 1, (long long) a[i]);
    pol[i] = min(pol[i], now);
  }
  now = -1e9;
  for (int i = n - 1; i >= 0; i--) {
    now = max(now + 1, (long long) a[i]);
    pol[i] = min(pol[i], now);
  }
  for (int i = 0; i < n; i++) {
    long long l = a[i], r = pol[i];
    while (l < r) {
      long long mid = (l + r + 1) >> 1;
      long long need = 0;
      
      int lf = 0, rf = i;
      while (lf < rf) {
        int mmid = (lf + rf) >> 1;
        if (slef.find(mmid, i) < mid + n - i) {
          rf = mmid;
        } else {
          lf = mmid + 1;
        }
      }
      //printf("lef hingga %d\n", lf);
      need += sum(mid - i + lf, mid) - find(lf, i);
      
      if (i + 1 < n && mid - 1 > a[i + 1]) {
        lf = i + 1, rf = n - 1;
        while (lf < rf) {
          int mmid = (lf + rf + 1) >> 1;

          if (srig.find(i+1, mmid) < mid + i) {
            lf = mmid;
          } else {
            rf = mmid - 1;
          }
        }
        //printf("rig hingga %d\n", lf);
        need += sum(mid - lf + i, mid - 1) - find(i + 1, lf);
      }
      
      //printf("%d to %lld need %lld\n", i, mid, need);
      
      if (need <= k) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    ans = max(ans, l);
  }
  cout << ans << endl;
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}