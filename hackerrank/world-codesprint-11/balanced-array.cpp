#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    n /= 2;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ans += x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ans -= x;
    }
    cout << abs(ans) << endl;
    return 0;
}
