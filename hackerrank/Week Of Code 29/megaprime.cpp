#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int hi[N], low[N];

vector<long long> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
long long fastmul(long long a, long long b, long long n) {
    long long k = (long long)(((long double) a * b / n) + 0.5);
    long long ret = a * b - k * n;
    ret %= n;
    if (ret < 0)
      ret += n;
    return ret;
}

long long fastexp(long long a, long long b, long long n) { // compute (a ^ b) mod n
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = fastmul(ret, a, n);
        a = fastmul(a, a, n);
        b >>= 1;
    }
    return ret;
}

bool mrtest(long long n)
{
    if(n == 1) return false;
    long long d = n-1;
    long long s = 0;
    while(d % 2 == 0)
    {
     s++;
     d /= 2;
    }
    for(long long j=0;j<(long long)A.size();j++)
    {
     if(A[j] > n-1) continue;
     long long ad = fastexp(A[j], d, n);
     if(ad % n == 1) continue;
     bool notcomp = false;
     for(long long r=0;r<=max(0LL,s-1);r++)
     {
       long long rr = fastexp(2,r,n);
       long long ard = fastexp(ad, rr, n);        
       if(ard % n == n-1) {notcomp = true; break;}
     }
     if(!notcomp)
     {
       return false;
     }
    }
    return true;
}

int d[] = {2, 3, 5, 7};

long long get(int id, bool bup, bool bdown, long long now) {
  if (id < 0) {
    return mrtest(now);
  }
  long long ret = 0;
  // 0
  if (bdown && low[id] == 0 && now == 0)
    ret += get(id-1, bup & (hi[id] == 0), bdown, 0);
  // 2. 3. 5. 7
  for (int i = 0; i < 4; i++) {
    if (d[i] > hi[id] && bup)
      continue;
    if (d[i] < low[id] && bdown)
      continue;
    ret += get(id-1, bup && (d[i] == hi[id]), bdown && (d[i] == low[id]), now * 10 + d[i]);
  }
  return ret;
}

int main() {
  long long first, last;
  cin >> first >> last;
  memset(low, 0, sizeof low);
  int k = 0;
  while (first) {
    low[k++] = first % 10;
    first /= 10;
  }
  k = 0;
  while (last) {
    hi[k++] = last % 10;
    last /= 10;
  }
  cout << get(k, 1, 1, 0) << endl;
  return 0;
}