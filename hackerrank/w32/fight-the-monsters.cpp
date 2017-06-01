#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
    int n, h, t;
    scanf("%d %d %d", &n, &h, &t);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    sort(a, a+n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k = (a[i] + h - 1) / h;
        if (t >= k)
            ans++, t -= k;
        else
            break;
    }
    printf("%d\n", ans);
    return 0;
}
