#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long u, v;
        cin >> u >> v;
        long long bef = u + v;
        bef = (bef + 1) * bef / 2;
        long long ans = bef + u + 1;
        cout << ans << endl;
    }
    return 0;
}