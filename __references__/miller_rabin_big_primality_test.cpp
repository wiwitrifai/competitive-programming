vector<ll> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

ll fastexp(ll a, ll b, ll n); // compute (a ^ b) mod n

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
     for(ll r=0;r<=max(0ull,s-1);r++)
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
