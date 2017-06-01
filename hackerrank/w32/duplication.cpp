#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    vector< int > s;
    s.push_back(0);
    while (s.size() <= 1000) {
        int n = s.size();
        for (int i = 0; i < n; i++)
            s.push_back(s[i] ^ 1);
    }
    while (t--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", s[x]);
    }
    return 0;
}
