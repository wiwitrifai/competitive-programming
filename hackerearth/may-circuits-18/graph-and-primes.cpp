#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5050, M = 1e6 + 5, inf = 1e9 + 7, K = 1001;
 
vector<int> g[N];
 
int u[M], v[M], w[M], ans[M];
int d[N];
int n, m;
set<pair<int, int> > st;
bool isPrime[M];
 
void dijkstra() {
    fill(d+1, d+n, inf);
    d[0] = 0;
    st.insert(make_pair(d[0], 0));
    while (!st.empty()) {
        auto it = st.begin();
        int cur = it->second;
        st.erase(it);
        for (int i : g[cur]) {
            int other = u[i]^v[i]^cur;
            if (d[other] > d[cur] + w[i]) {
                st.erase(make_pair(d[other], other));
                d[other] = d[cur] + w[i];
                st.insert(make_pair(d[other], other));
            }
        }
    }
}
 
int calc() {
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += isPrime[d[i]];
    return ans;
}
 
void copyAnswer() {
    for (int i = 0; i < m; ++i)
        ans[i] = w[i];
}
 
vector<int> prime;
int cnt[K];

void construct1() {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < m; ++i) {
        ++cnt[w[i]];
        w[i] = -1;
    }
    fill(d+1, d+n, inf);
    d[0] = 0;
    st.insert(make_pair(d[0], 0));
    int big = K-1;
    while (cnt[big] == 0 && big > 0) --big;
    while (!st.empty()) {
        auto it = st.begin();
        int cur = it->second;
        st.erase(it);
        set<int> pr;
        for (int i = 0; i < K; ++i) {
            if (cnt[i] <= 0) continue;
            if (isPrime[d[cur] + i])
                pr.insert(i);
        }
        for (int i : g[cur]) {
            int other = u[i]^v[i]^cur;
            if (w[i] == -1) {
                while (!pr.empty()) {
                    auto ix = pr.begin();
                    if (cnt[*ix] <= 0)
                        pr.erase(ix);
                    else {
                        --cnt[*ix];
                        w[i] = *ix;
                        break;
                    }
                }
                if (w[i] == -1) {
                    while (cnt[big] == 0 && big > 0) --big;
                    w[i] = big;
                    --cnt[big];
                }
            }
            if (d[other] > d[cur] + w[i]) {
                st.erase(make_pair(d[other], other));
                d[other] = d[cur] + w[i];
                st.insert(make_pair(d[other], other));
            }
        }
    }
}

void construct2() {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < m; ++i) {
        ++cnt[w[i]];
        w[i] = -1;
    }
    fill(d+1, d+n, inf);
    d[0] = 0;
    st.clear();
    st.insert(make_pair(d[0], 0));
    while (!st.empty()) {
        auto it = st.begin();
        int cur = it->second;
        st.erase(it);
        set<int> pr;
        for (int i = 0; i < K; ++i) {
            if (cnt[i] <= 0) continue;
            if (isPrime[d[cur] + i])
                pr.insert(i);
        }
        for (int i : g[cur]) {
            int other = u[i]^v[i]^cur;
            if (w[i] == -1) {
                while (!pr.empty()) {
                    auto ix = pr.begin();
                    if (cnt[*ix] <= 0)
                        pr.erase(ix);
                    else {
                        --cnt[*ix];
                        w[i] = *ix;
                        break;
                    }
                }
            }
            if (w[i] > 0 && d[other] > d[cur] + w[i]) {
                st.erase(make_pair(d[other], other));
                d[other] = d[cur] + w[i];
                st.insert(make_pair(d[other], other));
            }
        }
    }
    for (int i = 0; i < n; ++i)
        st.insert(make_pair(d[i], i));
    set<int> ada;
    for (int i = 0; i < K; ++i)
        if (cnt[i] > 0)
            ada.insert(i);
    while (!st.empty()) {
        auto it = st.begin();
        int cur = it->second;
        st.erase(it);
        for (int i : g[cur]) {
            int other = u[i]^v[i]^cur;
            if (w[i] == -1) {
                auto it = ada.lower_bound(d[other] - d[cur]);
                while (it != ada.end() && cnt[*it] == 0) {
                    auto del = it;
                    ++it;
                    ada.erase(del);
                }
                while (it == ada.end()) {
                    --it;
                    if (cnt[*it] == 0) {
                        ada.erase(it);
                        it = ada.end();
                    }
                }
                w[i] = *it;
                --cnt[*it];
            }
            if (d[other] > d[cur] + w[i]) {
                st.erase(make_pair(d[other], other));
                d[other] = d[cur] + w[i];
                st.insert(make_pair(d[other], other));
            }
        }
    }
}
 
 
int main() {
    srand(time(0));
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < M; ++i) if (isPrime[i]) {
        prime.push_back(i);
        for (long long j = 1LL * i * i; j < M; j += i) {
            isPrime[j] = 0;
        }
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", u+i, v+i), --u[i], --v[i];
        g[u[i]].push_back(i);
        g[v[i]].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", w+i);
    }
    construct1();
    dijkstra();
    int best = calc();
    copyAnswer();
    construct2();
    dijkstra();
    int cur = calc();
    if (cur > best) {
        best = cur;
        copyAnswer();
    }
    int acak = rand() % m + 1;
    int mi = (rand() % 5) + 1;
    while (clock() * 1000.0/CLOCKS_PER_SEC < 2800) {
        for (int i = 0; i < m; ++i)
            w[i] = ans[i];
        for (int i = 0; i < acak; ++i) {
            int a = rand() % m, b = rand() % m;
            swap(w[a], w[b]);
        }
        acak = acak / 2 + (rand() % mi) + 1;
        dijkstra();
        cur = calc();
        if (cur > best) {
            best = cur;
            copyAnswer();
        }
    }
    for (int i = 0; i < m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}