#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4, LG = 30;

int l[N * (LG+1)], r[N * (LG+1)], cnt[N * (LG+1)];

int nodes;

void add(int x, int id = 1) {
    for (int i = LG; i >= 0; i--) {
        cnt[id]++;
        if (x & (1 << i)) {
            if (!r[id])
                r[id] = ++nodes;
            id = r[id];
        }
        else {
            if (!l[id])
                l[id] = ++nodes;
            id = l[id];
        }
    }
    cnt[id]++;
}
void rem(int x, int id = 1) {
    for (int i = LG; i >= 0; i--) {
        cnt[id]--;
        if (x & (1 << i))
            id = r[id];
        else
            id = l[id];
    }
    cnt[id]--;
    assert(id != 0);
}
int get(int x, int y, int id = 1) {
    int ans = 0;
    for (int i = LG; i >= 0; i--) {
        if (y & (1 << i)) {
            if (x & (1 << i))
                ans += cnt[r[id]], id = l[id];
            else
                ans += cnt[l[id]], id = r[id];
        }
        else {
            if (x & (1 << i))
                id = r[id];
            else
                id = l[id];
        }
        if (!id) return ans;
    }
    return ans;
}
int main() {
    nodes = 1;
    int q;
    scanf("%d", &q);
    while (q--) {
        int t, x, y;
        scanf("%d %d", &t, &x);
        if (t == 1)
            add(x);
        else if (t == 2)
            rem(x);
        else {
            scanf("%d", &y);
            printf("%d\n", get(x, y));
        }
    }
    assert(nodes < N *(LG+1));
    return 0;
}