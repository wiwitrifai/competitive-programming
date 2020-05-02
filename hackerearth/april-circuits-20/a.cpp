#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    const int all = (1 << 16) - 1;
    while (t--) {
        int n, m;
        char s[5];
        scanf("%d %d %s", &n, &m, s);
        if (s[0] == 'L')
            n = (n << m) | (n >> (16 - m));
        else
            n = (n >> m) | (n << (16 - m));
        n &= all;
        printf("%d\n", n);
    }
    return 0;
}
