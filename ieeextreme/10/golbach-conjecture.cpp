/**
 *  IEEExtreme Programming Contest 10
 *  Problem : Goldbach's Second Conjecture
 *  Solver  : Wiwit Rifa'i
 *  Status  : Accepted
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
ll fastmul(ll a, ll b, ll n) {
    ll ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return ret;
}

ll fastexp(ll a, ll b, ll n) { // compute (a ^ b) mod n
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = fastmul(ret, a, n);
        a = fastmul(a, a, n);
        b >>= 1;
    }
    return ret;
}
bool mrtest(ll n)
{
    if(n == 1) return false;
    ll d = n-1;
    ll s = 0;
    while(d % 2 == 0)
    {
     s++;
     d /= 2;
    }
    for(ll j=0;j<(ll)A.size();j++)
    {
     if(A[j] > n-1) continue;
     ll ad = fastexp(A[j], d, n);
     if(ad % n == 1) continue;
     bool notcomp = false;
     for(ll r=0;r<=max(0ll,s-1);r++)
     {
       ll rr = fastexp(2,r,n);
       ll ard = fastexp(ad, rr, n);        
       if(ard % n == n-1) {notcomp = true; break;}
     }
     if(!notcomp)
     {
       return false;
     }
    }
    return true;
}

const int N = 5e6 + 5;

bitset< N > isp;
vector< int > prime;

int main() {
    isp.set();
    isp[0] = isp[1] = 0;
    for (int i = 2; i < N; i++) if (isp[i]) {
        prime.push_back(i);
        for (ll j = 1LL * i * i; j < N; j += i)
            isp[j] = 0;
    }
    long long n;
    cin >> n;
    long long a = -1, b, c;
    for (int i = 4; i < N && a < 0; i += 2) {
        long long m = n - i;
        if (mrtest(m)) {
            for (int j = 0; prime[j] < i && a < 0; j++) {
                if (isp[i-prime[j]]) {
                    a = m;
                    b = prime[j];
                    c = i-prime[j];
                    break;
                }
            } 
        }
    }
    if (a < 0)
        puts("counterexample");
    else
        printf("%lld %lld %lld\n", a, b, c);

    return 0;
}