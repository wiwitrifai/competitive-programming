#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t, n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d", &n);
        int i, j;
        i = n/2;
        if(n & 1) {
            printf("%d ", (n+1)/2);
            j = i+2;
        }
        else
            j = i+1;
        for(; i; i--, j++)
            printf("%d %d%c", i, j, (i == 1) ? '\n' : ' ');
    }
    return 0;
}