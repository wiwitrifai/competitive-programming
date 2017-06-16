#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (((c-a) % e) || ((d-b) % f))
        puts("NO");
    else {
        long long x = (c-a)/e, y = (d-b)/f;
        puts(((x & 1) == (y & 1)) ? "YES" : "NO");
    }
    return 0;
}