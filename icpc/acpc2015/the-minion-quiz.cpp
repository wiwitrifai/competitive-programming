#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        unsigned long long x, now;
        scanf("%llu", &now);
        while(a--) {
            scanf("%llu", &x);
            now &= x;
        }
        while(b--) {
            scanf("%llu", &x);
            now |= x;
        }
        printf("%llu\n", now);
        
    }
    return 0;
}
