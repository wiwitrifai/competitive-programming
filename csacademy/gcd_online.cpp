#include <bits/stdc++.h>

using namespace std;

const int N = 1<<17;

int a[N];
int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

void upd(int id, int val) {
    a[N+id] = val;
    int now = (N+id) >> 1;
    while(now) {
        a[now] = gcd(a[now+now], a[now+now+1]);
        now >>=1;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
        int x;
        scanf("%d", &x);
        upd(i, x);
    }
    while(m--) {
        int id, x;
        scanf("%d%d", &id, &x);
        upd(id-1, x);
        printf("%d\n", a[1]);
    }
}
