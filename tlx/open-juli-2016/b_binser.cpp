#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t[N], x[N];
bool used[N];
long long prefix[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", t+i);
  }
  memset(used, 0, sizeof used);

  int l, r;
  l = 1, r = 1;
  used[t[l]] = true;
  while (l <= n) {
    // cek jika r masih bisa maju
    if (r+1 <= n && !used[t[r+1]]) {
      r++;
      used[t[r]] = true;
    }
    else {
      // r sudah tidak bisa maju berarti sub array [l, r] adalah subarray terpanjang yg dimulai dari 
      // indeks l dengan semua elemennya berbeda
      x[l] = r;
      // majukan l untuk melanjutkan pencarian untuk x[l+1]
      used[t[l]] = false;
      l++;
    }
  }

  for (int i = 1; i <= n; i++)
    prefix[i] = prefix[i-1] + x[i] - i + 1;
  
  while (q--) {
    scanf("%d %d", &l, &r);
    int batas = upper_bound(x+l, x+r+1, r) - x;
    long long ans = prefix[batas-1] - prefix[l-1];
    int sisa = r-batas+1;
    ans += 1LL * sisa * (sisa+1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}