#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, s;
    cin >> n >> s;
    long long t = min(s + 200LL, n);
    long long ans = n-t;
    for (long long x = s; x <= t; x++) {
        long long c = x;
        long long sum = 0;
        while (c) {
            sum += c % 10;
            c /= 10;
        }
        if (x - sum >= s) ans++;
    }
    cout << ans << endl;

    return 0;
}