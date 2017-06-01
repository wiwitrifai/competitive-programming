#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5, inf = 1e9;

int n, r[N], m[N], id[N], s[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        scanf("%d", r+i);   
    }
    for(int i = 0; i<n; i++) {
        scanf("%d", m+i);
        id[i] = i;
        s[i] = 0;
    }
    sort(id, id+n, [](int a, int b) { return r[a] == r[b] ? m[a] > m[b] : r[a] < r[b]; });
    for(int i = 0; i<n; i++) {
        int now = id[i];
        int t = now;
        for(int j = 1; j<=10; j++) {
            if(now + j < n && (s[now + j] > s[t] && r[now+j] < r[now]))
                t = now+j;
            if(now - j >= 0 && (s[now - j] > s[t] && r[now-j] < r[now]))
                t = now-j;
        }
        s[now] = max(s[t]+1, m[now]);
    }
    long long sum = 0;
    for(int i = 0; i<n; i++) {
     //   printf("%d ", s[i]);
        sum += s[i];
    }
    printf("%lld\n", sum);
    return 0;
}