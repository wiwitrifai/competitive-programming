#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long base;

const int MAXN = 131072*2 + 5;
const ld PI = acosl(-1);
const ll MOD = 998244353;
//const ll MOD = 1e18;

int rev[MAXN];
base wlen_pw[20][MAXN];

// MOD not equal 1
ll power(ll b,ll p,ll MOD)
{
    ll ret = 1;
    while(p)
    {
        if(p&1)
            ret = ret * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return ret;
}

/*
    Should call calc_rev and pre before calling this function.
*/
void fft (base a[], int n, bool invert) {
  for (int i=0; i<n; ++i)
    if (i < rev[i])
      swap (a[i], a[rev[i]]);

    int LG = 1;
  for (int len=2; len<=n; len<<=1,LG++) {
    int len2 = len>>1;


    for (int i=0; i<n; i+=len) {
      base t,
        *pu = a+i,
        *pv = a+i+len2,
        *pu_end = a+i+len2,
        *pw = wlen_pw[LG];
      for (; pu!=pu_end; ++pu, ++pv, ++pw) {
        t = (*pv * *pw) % MOD;
        *pv = (*pu - t + MOD) % MOD;
        *pu = (*pu + t) % MOD;
      }
    }
  }
    ll inv_n = power(n,MOD-2,MOD);
  if (invert)
    for (int i=0; i<n; ++i)
      a[i] = (a[i] * inv_n) % MOD;
}

void calc_rev (int n, int log_n) {
  for (int i=0; i<n; ++i) {
    rev[i] = 0;
    for (int j=0; j<log_n; ++j)
      if (i & (1<<j))
        rev[i] |= 1<<(log_n-1-j);
  }
}

inline void print(const vector<ll> &cc)
{
    for(int i=0;i<cc.size();i++)
        cout<<(cc[i] > MOD / 2 && true? cc[i] - MOD: cc[i])<<" \n"[i+1==cc.size()];
}

inline void print(vector<base> &cc)
{
    for(int i=0;i<cc.size();i++)
        cout<<fixed<<cc[i]<<" \n"[i+1==cc.size()];
}

void pre(int n,bool invert)
{
    int LG = 1;
    for (int len=2; len<=n; len<<=1, LG++) {
        int len2 = len>>1;
    base wlen = power(3,(MOD-1)/len,MOD);
    if(invert)
            wlen = power(wlen,MOD-2,MOD);
    wlen_pw[LG][0] = 1;
    for (int i=1; i<len2; ++i)
      wlen_pw[LG][i] = wlen_pw[LG][i-1] * wlen % MOD;
    }
}

vector<ll> multiply(vector<ll> A,vector<ll> B)
{
    int n = 1;
    int log_n = 0;
    while(n < max(A.size(), B.size()))
        n <<= 1, log_n++;
    n <<= 1, log_n++;
    A.resize(n),B.resize(n);
    calc_rev(n,log_n);
    pre(n,false);
    fft(A.data(),n,false), fft(B.data(),n,false);
    vector<base> X(n),Y(n),Z(n);
    for(int i=0;i<n;i++)
        A[i] = A[i] * B[i] % MOD;
    pre(n,true);
    fft(A.data(),n,true);
    return A;
}

/*
    Inverse of polynomial A modulo x^n
*/
vector<ll> inverse_Generating_Function(vector<ll> A, int n)
{
    int n2 = 1;
    while(n2 < n)
        n2 <<= 1;
    n = n2;
    A.resize(n);

    n2 = 1;
    vector<base> prev;
    ll inv = power(A[0],MOD-2,MOD); // 1/A[0] % MOD
    prev.push_back(inv);
    int log_n2 = 0;
    while(n2 < n)
    {
        n2 <<= 2, log_n2+=2;
        vector<ll> F (n2);
        for(int i=0,n3=(n2>>1);i<n3;i++)
            F[i] = A[i];
        prev.resize(n2);
        vector<ll> old = prev;
        calc_rev(n2,log_n2);
        pre(n2,false);
        fft(prev.data(),n2,false);
        fft(F.data(),n2,false);
        for(int i=0;i<n2;i++)
            prev[i] = (2*prev[i] - prev[i] * prev[i] % MOD * F[i] % MOD + MOD) % MOD;
        pre(n2,true);
        fft(prev.data(),n2,true);
        n2 >>= 1, log_n2--;
        prev.resize(n2);
    }
    return prev;
}

vector<ll> generate(int l, int r) {
    if (l > r)
        return {1};
    if (l == r)
        return {-l, 1};
    int mid = (l + r) >> 1;
    vector<ll> le = generate(l, mid), ri = generate(mid+1, r);
    return multiply(le, ri);
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if (a == 1 && b == 1) {
        if (n == 1)
            puts("1");
        else
            puts("0");
        return 0;
    }
    vector<ll> le = generate(1, a-1), ri = generate(1, b-1);
    // for (int i = 0; i < le.size(); ++i)
    //     cerr << le[i] << " ";
    // cerr << endl;
    // for (int i = 0; i < ri.size(); ++i)
    //     cerr << ri[i] << " ";
    // cerr << endl;
    le = inverse_Generating_Function(le, n+1), ri = inverse_Generating_Function(ri, n+1);
    // for (int i = 0; i < le.size(); ++i)
    //     cerr << le[i] << " ";
    // cerr << endl;
    // for (int i = 0; i < ri.size(); ++i)
    //     cerr << ri[i] << " ";
    // cerr << endl;
    vector<ll> vl(n+1, 0), vr(n+1, 0);
    for (int i = a-1; i <= n; ++i)
        vl[i] = le[i-(a-1)];
    for (int i = a-1; i <= n; ++i)
        vr[i] = ri[i-(b-1)];
    vector<ll> res = multiply(vl, vr);
    printf("%lld\n", res[n-1]);
    return 0;
}