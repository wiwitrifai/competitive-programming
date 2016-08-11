#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

bitset< N > isprim;
vector< long long > prime;
int m;

long long get(long long x) {
  long long pos, neg;
  pos = x; neg = 0;
  long long add = 0;
  cerr << " get " << x << endl;
  for(int i = 0; i<prime.size(); i++) {
    if(prime[i] > x)
      break;
    add++;
    long long tpos = pos + neg/prime[i];
    long long tneg = neg + pos/prime[i];
    pos = tpos;
    neg = tneg;
    cerr << prime[i] << " " << pos << " " << tneg << " " << pos - neg <<endl; 
  }
  return add + pos - neg;
}

int main() {
  isprim.set();
  isprim[1] = 0;
  for(int i = 2; i < N; i++) if(isprim[i]) {
    for(long long j = 1LL * i * i; j < N; j += i)
      isprim[j] = 0;
    prime.push_back(i);
  }
  cerr << get(100) << endl;
  long long n;
  cin >> n;
  long long ans = 0;
  for(int i = 0; i<prime.size(); i++) {
      long long id = get(n/prime[i]) - 2;
      if(id <= i)
        break;
      ans += id - i;
  }
  for(int i = 0; i<prime.size(); i++) {
    long long pp = 1LL * prime[i] * prime[i] * prime[i];
    if(pp <= n)
      ans++;
    else
      break;
  }
  cout << ans << endl;

  return 0;
}