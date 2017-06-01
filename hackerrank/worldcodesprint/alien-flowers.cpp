#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

long long fac[N], inv[N];

long long powmod(long long base, long long pw) {
    long long ret = 1;
    while(pw) {
        if(pw & 1)
            ret = (ret * base) % mod;
        base = (base * base) % mod;
        pw >>= 1;
    }
    return ret;
}

long long comb(int n, int m) {
    if(n < m || n < 0 || m < 0)
        return 0;
    return (((fac[n] * inv[m]) % mod)*inv[n-m] % mod) % mod;
}

int main(){
    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1; i<N; i++) {
        fac[i] = (fac[i-1] * i) % mod;
        inv[i] = powmod(fac[i], mod-2);
    }
    int A;
    int B;
    int C;
    int D;
    cin >> A >> B >> C >> D;
    long long ans = 0;
    if(B == D) {
        if(B == 0) {
            if(A == 0 && C == 0)
                ans = 2;
            else
                if(A != 0 && C != 0)
                    ans = 0;
                else
                    ans = 1;
        }
        else
            ans = (comb(A+B , B)*comb(B+C-1, C) + comb(A+B-1, A)*comb(B+C, C))  % mod;
    }
    else {
        if(B > D) {
            swap(B, D);
            swap(A, C);
        }
        if(D == B+1) {
            ans = comb(A+D-1, D-1)*comb(C+D-1, D-1) % mod;
        }
    }
    ans %= mod;
    if(ans < 0)
        ans += mod;
    cout << ans << endl;
    return 0;
}