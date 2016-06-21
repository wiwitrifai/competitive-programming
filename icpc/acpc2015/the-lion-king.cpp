#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int mod = 1e9 + 7;

int x[N], y[N], cnt[N], down[N];
long long cl[N], cr[N];

int pos[N][N];
vector< int > ver, hor;

int main() {
  memset(pos, 0, sizeof pos);
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    ver.clear();
    hor.clear();
    for(int i = 0; i<n; i++) {
      scanf("%d%d", x+i, y+i);
      ver.push_back(y[i]);
      hor.push_back(x[i]);
    }
    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end());
    ver.erase(unique(ver.begin(), ver.end()), ver.end());
    hor.erase(unique(hor.begin(), hor.end()), hor.end());
    for(int i = 0; i<hor.size(); i++)
      cnt[i] = 0;
    for(int i = 0; i<n; i++) {
      int p = lower_bound(hor.begin(), hor.end(), x[i])-hor.begin();
      int q = lower_bound(ver.begin(), ver.end(), y[i])-ver.begin();
      x[i] = p;
      y[i] = q;
      pos[q][p]++;
      cnt[p]++;
    }
    memset(down, 0, sizeof down);
    // for(int i = 0; i<ver.size(); i++) {
    //   for(int j = 0; j<hor.size(); j++)
    //     cout << pos[i][j] << " ";
    //   cout << endl;
    // }
    // cout << " ha " << endl;
    long long ans = 0;
    for(int i = 0; i<ver.size(); i++) {
      long long now = 0, mul = 0;
      for(int j = 0; j<hor.size(); j++) {
        cnt[j]-= pos[i][j];
        now = (now + ((mul * down[j]) % mod)) % mod;
        mul = (mul + pos[i][j]) % mod;
        cl[j] = now;
      }
      now = mul = 0;
      for(int j = (int)hor.size()-1; j>= 0; j--) {
        now = (now + ((mul * down[j]) % mod)) % mod;
        mul += pos[i][j];
        cr[j] = now;
      }
      // for(int j = 0; j<hor.size(); j++)
      //   cout << cnt[j] << " ";
      // cout << endl;
      // for(int j = 0; j<hor.size(); j++)
      //   cout << cl[j] << " ";
      // cout << endl;
      // for(int j = 0; j<hor.size(); j++)
      //   cout << cr[j] << " ";
      // cout << endl;
      // cout << endl;
      for(int j = 1; j+1<hor.size(); j++) {
        ans = (ans + (((cnt[j]*cl[j-1] % mod)*cr[j+1]) % mod)) % mod;
      }
      for(int j = 0; j<hor.size(); j++)
        down[j] += pos[i][j];
    }
    for(int i = 0; i<n; i++)
      pos[y[i]][x[i]]--;
    if(ans < 0)
        ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}