#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 7;

double ss[N];

int main() {
    for (int i = 0; i < N; i++)
        ss[i] = sin(i);
    int n;
    cin >> n;
    for (n = 3; n <= 100; n++) {
    double ans = ss[1] + ss[1] + ss[n-2];
    for (int i = n-3; 3*i >= n; i--) {
        double a = ss[i];
        int m = n-i;
        for (int j = min(i, m-1); j+j >= m; j--)
            ans = max(ans, a+ss[j]+ss[m-j]);
    }
    printf("%.9lf\n", ans);
}
    return 0;
}
