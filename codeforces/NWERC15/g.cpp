#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5;
int fA[N + 5], fB[N + 5], fC[N + 5], mapA[N + 5], B[N + 5], C[N + 5], mapB[N + 5];
LL AnsB[N + 5];
LL AnsC[N + 5];
LL BIT[N + 5];
int n;

void update(int idx, LL val){
    for(int i = idx; i <= n; i += (i&-i)){
        BIT[i] += val;
    }
}

LL query(int idx){
    LL ans = 0;
    for(int i = idx; i > 0; i -= (i&-i)) ans += BIT[i];
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i < n; ++i){
        scanf("%d", &fA[i]);
        mapA[fA[i]] = i + 1;
    }
    for(int i = 0;i < n; ++i){
        scanf("%d", &fB[i]);
        B[i] = mapA[fB[i]];
    }
    for(int i = 0;i < n; ++i){
        scanf("%d", &fC[i]);
        C[i] = mapA[fC[i]];
    }
    LL tot = 0;
    memset(BIT, 0, sizeof BIT);
    for(int i = 0;i < n; ++i){
        tot += query(B[i] - 1);
        update(B[i], 1);
    }
    memset(BIT, 0, sizeof BIT);
    for(int i = 0;i < n; ++i){
        tot += query(C[i] - 1);
        update(C[i], 1);
    }
    for (int i = 0; i < n; i++) {
        mapB[B[i]] = i+1;
    }
    for (int i = 0; i < n; i++) {
        C[i] = mapB[C[i]];
    }
    memset(BIT, 0, sizeof BIT);
    for (int i = 0; i < n; i++) {
        tot += query(C[i] - 1);
        update(C[i], 1);
    }
    tot -= 1LL * n * (n-1) / 2;
    assert((tot & 1) == 0);
    tot /= 2;
    printf("%I64d\n", tot);
    return 0;
}