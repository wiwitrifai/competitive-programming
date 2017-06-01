#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;

char s[N][N];
bool used[N][N];

int n, m, dx[] = {0,0,-1,1}, dy[] = {-1, 1, 0, 0};

int ans;

int solve(int lv = 0, int last = 0) {
    int now = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(s[i][j] != 'G' || used[i][j])
                continue;
            for(int k = 1; k<N; k++) {
                bool ok = true;
                for(int b = 0; b < 4; b++) {
                    int x = i + k*dx[b], y = j + k*dy[b];
                    if(!(x < n && x >= 0 && y < m && y >= 0 && s[x][y] == 'G' && !used[x][y])) {
                        ok = false;
                    }
                }
                if(!ok) {
                    now = max(now, k*4-3);
                    break;
                }
            }
        }
    }
    return now;
}


int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
        scanf("%s", s[i]);
    }
    ans = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(s[i][j] != 'G')
                continue;
            int k;
            for(k = 1; k<N; k++) {
                bool ok = true;
                for(int b = 0; b < 4; b++) {
                    int x = i + k*dx[b], y = j + k*dy[b];
                    if(!(x < n && x >= 0 && y < m && y >= 0 && s[x][y] == 'G')) {
                        ok = false;
                    }
                }
                if(!ok)
                    break;
            }
            used[i][j] = 1;
            for(int c = 1; c<k; c++) {
                for(int b = 0; b < 4; b++) {
                    int x = i + c*dx[b], y = j + c*dy[b];
                    used[x][y] = 1;
                }
            }
            ans = max(ans, solve()*(4*k-3));
            used[i][j] = 0;
            for(int c = 1; c<k; c++) {
                for(int b = 0; b < 4; b++) {
                    int x = i + c*dx[b], y = j + c*dy[b];
                    used[x][y] = 0;
                }
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
