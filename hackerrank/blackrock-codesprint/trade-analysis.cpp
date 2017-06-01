#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

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

int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    long long mul = 1;
    while(n--) {
        int x;
        scanf("%d", &x);
        sum += (powmod(x+1, mod-2) * x) % mod;
        sum %= mod;
        mul = (mul * (x+1)) % mod;
    }
    long long ans = (mul * sum) % mod;
    if(ans < 0)
        ans += mod;
    printf("%lld\n", ans);
    return 0;
}
