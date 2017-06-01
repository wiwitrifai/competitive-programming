#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
char s[50];
int a[N], ch[N][2];
pair< long long, long long > dfs(int v) {
    pair< long long, long long > ret = make_pair(a[v], 0), res;
    if(ch[v][0] >= 0) {
        res = dfs(ch[v][0]);
        ret.first += res.second;
        ret.second += res.first;
    }
    if(ch[v][1] >= 0) {
        res = dfs(ch[v][1]);
        ret.first += res.second;
        ret.second += res.first;
    }
    ret.first = max(ret.first, ret.second);
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int cur = 0;
    queue< int > q;
    scanf("%s", s);
    if(s[0] != '#') {
        a[cur] = atoi(s);
        q.push(cur++);
    }
    while(cur < n && !q.empty()) {
        int now = q.front(); q.pop();
        ch[now][0] = ch[now][1] = -1;
        if(scanf("%s", s) != 1)
            break;
        if(s[0] != '#') {
            ch[now][0] = cur;
            a[cur] = atoi(s);
            q.push(cur);
            cur++;
        }
        if(scanf("%s", s) != 1)
            break;
        if(s[0] != '#') {
            ch[now][1] = cur;
            a[cur] = atoi(s);
            q.push(cur);
            cur++;
        }
    }
    while(!q.empty()) {
        int now = q.front(); q.pop();
        ch[now][0] = ch[now][1] = -1;
    }

    printf("%lld\n", dfs(0).first);
    return 0;
}
