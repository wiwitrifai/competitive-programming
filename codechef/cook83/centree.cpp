#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, b;
        scanf("%d %d", &n, &b);
        if (n == 2 && b == 0) {
            puts("NO");
            continue;
        }
        if (n == 2 && b == 1) {
            puts("YES");
            printf("%d %d\n", 1, 2);
            continue;
        }
        if (n >= 4 * b) {
            puts("YES");
            if (n > 1) {
                for (int i = 0; i < 2 * b + 1; i++) {
                    printf("%d %d\n", i+1, i+2);
                }
                for (int i = 2 * b + 3; i <= n; i++)
                    printf("%d %d\n", 2, i);
            }
        }
        else
            puts("NO");
    }
    return 0;
}