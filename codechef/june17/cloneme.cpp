#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long powmod(long long b, long long p, long long m) {
    long long r = 1;
    for (; p; p >>= 1, b = b * b % m)
        if (p & 1) r = r * b % m;
    return r;
}

const int K = 2;
int p[] = {23, 31}, mod[] = {(int)(1e9 + 7), (int)(1e9 + 9)};

struct hsh {
    int v[K];
    hsh() {
        memset(v, 0, sizeof v);
    }
    hsh(int a) {
        for (int i = 0; i < K; i++)
            v[i] = powmod(p[i], a, mod[i]);
    }
    hsh operator+(const hsh& oth) {
        hsh ret;
        for (int i = 0; i < K; i++) {
            ret.v[i] = v[i] + oth.v[i];
            if (ret.v[i] >= mod[i])
                ret.v[i] -= mod[i];
        }
        return ret;
    }
    bool operator==(const hsh& oth) {
        for (int i = 0; i < K; i++)
            if (v[i] != oth.v[i]) return false;
        return true;
    }
    void reset() {
        memset(v, 0, sizeof v);
    }
};

struct node {
    int il, ir;
    hsh h;
} nodes[40 * N];
int n, q, m;
int a[N], r[N], cnode;
int va[N];
int build(int l = 0, int r = n) {
    int id = ++cnode;
    // cerr << id << " " << l << " " << r << endl;
    nodes[id].h.reset();
    nodes[id].il = nodes[id].ir = 0;
    if (r-l < 2)
        return id;
    int mid = (l + r) >> 1;
    nodes[id].il = build(l, mid);
    nodes[id].ir = build(mid, r);
    return id;
}
int add(int x, const hsh & hh, int id, int l = 0, int r = n) {
    // cerr << x << " " << id << " " << l << " " << r << endl;
    int ID = ++cnode;
    nodes[ID].il = nodes[id].il;
    nodes[ID].ir = nodes[id].ir;
    nodes[ID].h = nodes[id].h + hh;
    if (r-l < 2)
        return ID;
    int mid = (l + r) >> 1;
    if (x < mid)
        nodes[ID].il = add(x, hh, nodes[ID].il, l, mid);
    else
        nodes[ID].ir = add(x, hh, nodes[ID].ir, mid, r);
    return ID;
}
int getl(int a, int b, int c, int d, int l = 0, int r = n) {
    if (r-l < 2) {
        return l + ((nodes[b].h+nodes[c].h) == (nodes[a].h+nodes[d].h));
    }
    int mid = (l + r) >> 1;
    int la = nodes[a].il, lb = nodes[b].il, lc = nodes[c].il, ld = nodes[d].il;
    if ((nodes[lb].h+nodes[lc].h) == (nodes[la].h+nodes[ld].h))
        return getl(nodes[a].ir, nodes[b].ir, nodes[c].ir, nodes[d].ir, mid, r);
    else
        return getl(la, lb, lc, ld, l, mid);
}
int getr(int a, int b, int c, int d, int l = 0, int r = n) {
    if (r-l < 2) {
        return r - ((nodes[b].h+nodes[c].h) == (nodes[a].h+nodes[d].h));
    }
    int mid = (l + r) >> 1;
    int ra = nodes[a].ir, rb = nodes[b].ir, rc = nodes[c].ir, rd = nodes[d].ir;
    if ((nodes[rb].h+nodes[rc].h) == (nodes[ra].h+nodes[rd].h))
        return getr(nodes[a].il, nodes[b].il, nodes[c].il, nodes[d].il, l, mid);
    else
        return getr(ra, rb, rc, rd, mid, r);
}
hsh calc(int x, int y, int id, int l = 0, int r = n) {
    if (x >= r || l >= y) return hsh();
    if (x <= l && r <= y) return nodes[id].h;
    int mid = (l + r) >> 1;
    return calc(x, y, nodes[id].il, l, mid) + calc(x, y, nodes[id].ir, mid, r);
}

vector< int > vid[N];
int cnt(int x, int l, int r) {
   return lower_bound(vid[x].begin(), vid[x].end(), r) - lower_bound(vid[x].begin(), vid[x].end(), l);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &m, &q);
        for (int i = 0; i < m; i++)
            scanf("%d", a+i), va[i] = a[i];
        sort(va, va+m);
        n = unique(va, va+m) - va;
        for (int i = 0; i < n; i++) vid[i].clear();
        for (int i = 0; i < m; i++) {
            vid[lower_bound(va, va+n, a[i])-va].push_back(i);
        };
        cnode = 0;
        r[0] = build();
        for (int i = 0; i < m; i++) {
            hsh h(a[i]);
            int x = lower_bound(va, va+n, a[i]) - va;
            // cerr << x << endl;
            r[i+1] = add(x, h, r[i]);
        }
        while (q--) {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            a--; c--;
            int ll = getl(r[a], r[b], r[c], r[d]);
            if (ll >= n) {
                puts("YES");
                continue;
            }
            int rr = getr(r[a], r[b], r[c], r[d]);
            if (ll >= rr) {
                puts("YES");
                continue;
            }
            rr--;
            if (ll+1 <= rr) {
                if (!(calc(ll+1, rr, r[a]) == calc(ll+1, rr, r[b])) || !(calc(ll+1, rr, r[c]) == calc(ll+1, rr, r[d]))) {
                    puts("NO");
                    continue;
                }
            }
            int cnta = cnt(ll, a, b), cntb = cnt(ll, c, d);
            if (cnta > cntb)
                swap(a, c), swap(b, d), swap(cnta, cntb);
            if (cnta + 1 != cntb) {
                puts("NO");
                continue;
            }
            cnta = cnt(rr, a, b), cntb = cnt(rr, c, d);
            if (cnta != cntb + 1)
                puts("NO");
            else
                puts("YES");
        }
    }
    return 0;
}