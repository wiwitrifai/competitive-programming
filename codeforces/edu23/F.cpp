#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;

vector< long long > vx;
int n;
int t[N];
long long a[N], b[N];
pair< long long, long long > seg[N << 2];
int lazy[N << 2];
void build(int id = 1, int l = 0, int r = n) {
    lazy[id] = 0;
    if (r-l < 2) {
        seg[id] = {vx[l], vx.back()};
        return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
    seg[id] = {min(seg[il].first, seg[ir].first), min(seg[il].second, seg[ir].second)};
}

void push(int id, int l, int r) {
    if (lazy[id] == 1) {
        int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
        seg[il] = {vx.back(), vx[l]};
        seg[ir] = {vx.back(), vx[mid]};
        lazy[il] = lazy[ir] = 1;
    }
    else if (lazy[id] == 2) {
        int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
        seg[il] = {vx[l], vx.back()};
        seg[ir] = {vx[mid], vx.back()};
        lazy[il] = lazy[ir] = 2;
    }
    else if (lazy[id] == 3) {
        int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
        swap(seg[il].first, seg[il].second);
        swap(seg[ir].first, seg[ir].second);
        lazy[il] = 3 - lazy[il];
        lazy[ir] = 3 - lazy[ir];
    }
    lazy[id] = 0;
}

void update(int x, int y, int tp, int id = 1, int l = 0, int r = n) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
        if (r - l >= 2)
            push(id, l, r);
        lazy[id] = tp;
        if (tp == 1)
            seg[id] = {vx.back(), vx[l]};
        else if (tp == 2)
            seg[id] = {vx[l], vx.back()};
        else if (tp == 3)
            swap(seg[id].first, seg[id].second);
        return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    update(x, y, tp, il, l, mid);
    update(x, y, tp, ir, mid, r);
    seg[id] = {min(seg[il].first, seg[ir].first), min(seg[il].second, seg[ir].second)};
}

int main() {
    int q;
    scanf("%d", &q);
    vx.push_back(1);
    for (int i = 0; i < q; i++) {
        scanf("%d %I64d %I64d", t+i, a+i, b+i);
        vx.push_back(a[i]);
        vx.push_back(b[i]+1);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    n = (int)vx.size() - 1;
    build();
    for (int i = 0; i < q; i++) {
        int l = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin();
        int r = lower_bound(vx.begin(), vx.end(), b[i]+1) - vx.begin();
        update(l, r, t[i]);
        printf("%I64d\n", seg[1].first);
    }
    return 0;
}