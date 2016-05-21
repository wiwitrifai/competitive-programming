#include <bits/stdc++.h>

using namespace std;

long long cek(long long n) {
  long long ret = 0;
  while(n) {
    ret += n/5;
    n /= 5;
  }
  return ret;
}

int main() {
  long long m;
  long long la, ra;
  cin >> m;
  la = 0;
  ra = m;
  long long l, r;
  l = 0; r = 5*(m+1);
  while(l < r) {
    long long mid = (l+r+1)/2;
    if(cek(mid) > m)
      r = mid-1;
    else
      l = mid;
  }
  ra = r;
  r++;
  l = 0;
  while(l < r) {
    long long mid = (l+r)/2;
    if(cek(mid) < m)
      l = mid+1;
    else
      r = mid;
  }
  la = l;
  cout << max(0LL, ra-la+1) << endl;
  for(int i = la; i<ra; i++)
    cout << i << " ";
  if(la <= ra)
    cout << ra << endl;
  return 0;
}