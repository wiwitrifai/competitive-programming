#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, p, q;

int main() {
  cin >> n >> a >> p;
  cin >> m >> b >> q;
  long long nm = b*m;
  int l = (q-1) * b - a, r = q * b;
  long long off = (n-p+1), roll = a*n;
  long double addd = 0;
  long double add = (long double)(180 - 180*(m-2)/m);
  if(p == 1)
    off = 0;
  long long cnt = off;
  off *= a;
  off %= nm;
  while(l < 0) {
    r += b;
    off += b;
    l += b;
    addd -= add;
  }
  bool ketemu = false;
  for(int i = 0; i<nm; i++) {
    if(off < r && off > l) {
      ketemu = true;
      break;
    }
    cnt += n;
    off += roll;
    while(off >= nm) {
      off -= nm;
      cnt+= n;
    }
  }
  if(!ketemu) {
    puts("-1");
    return 0;
  }
  off %= nm;
  if(off < 0)
    off += nm;
  long long now = 0;
  while(now + b <= off) {
    // cout << now << " " << off << endl;
    now += b;
    addd += add;
  }
  if(off > l && off < r-b) {
    addd += add;
  }
  // cout << cnt << endl;
  cout << fixed << setprecision(15) << (long double)360.0*cnt/n + addd << endl;
  // cout << addd << endl;
  return 0;
}