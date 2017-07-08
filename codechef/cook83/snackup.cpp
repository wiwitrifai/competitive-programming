#include <bits/stdc++.h>

using namespace std;

int ans;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", n);
        for (int r = 0; r < n; r++) {
            printf("%d\n", n);
            for (int i = 0; i < n; i++) {
                printf("%d %d %d\n", i+1, ((i+r) % n) + 1, ((i+r+1) % n) + 1);
            }
        }
    }
    return 0;
}