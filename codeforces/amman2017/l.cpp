#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int INF = 1e9;
const double EPS = 1e-9;
const int N = 2000, M = 5000;
int poi[N + 5];
pii ve[N + 5][M + 5];
piii edge[M + 5];
int dist[N + 5];
set<pii> pq;
int n, m;
int A[M + 5], B[M + 5], C[M + 5];

bool checkBellmanFord(){
    for(int i = 0;i <= n; ++i) dist[i] = INF;
    dist[0] = 0;
    for(int loop = 1; loop < n; ++loop){
        for(int i = 0;i < m; ++i){
            if(dist[A[i]] + C[i] < dist[B[i]]){
                dist[B[i]] = dist[A[i]] + C[i];
            }
        }
    }

    for(int i = 0;i < m; ++i){
        if(dist[A[i]] + C[i] < dist[B[i]]){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int minEdge = INF;
        memset(poi, 0, sizeof poi);
        for(int i = 0;i < m; ++i){
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            ve[x][poi[x]] = mp(y, c);
            poi[x]++;
            minEdge = min(minEdge, c);
      A[i] = x;
      B[i] = y;
      C[i] = c;
            edge[i] = mp(mp(x, y), c);
        }
        if(minEdge >= 0){
            printf("%d\n", minEdge);
            continue;
        }
        bool valid = checkBellmanFord();
        if(!valid){
            puts("-inf");
            continue;
        }
        int mindist = INF;
        pq.clear();
        for(int i = 0;i <= n; ++i) {
            dist[i] = 0;
            pq.insert(mp(0, i));
        }
        while(!pq.empty()){
            auto it = pq.begin();
            pii top = *it; pq.erase(it);
            if (top.fi != dist[top.se]) continue;
            for(int j = 0;j < poi[top.se]; ++j){
                int t = ve[top.se][j].fi;
                int c = ve[top.se][j].se;
                if(top.fi + c < dist[t]){
                    if (dist[t] != INF)
                        pq.erase(mp(dist[t], t));
                    dist[t] = top.fi + c;
                    mindist = min(mindist, dist[t]);
                    pq.insert(mp(dist[t], t));
                }
            }
        }
        for (int i = 0; i <= n; i++)
            mindist = min(mindist, dist[i]);
        printf("%d\n", mindist);
    }
    return 0;
}