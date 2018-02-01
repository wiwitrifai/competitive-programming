#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int,int> t4i;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 55;
const int N_D = 11;
const int T = 100;
const int N_ARAH = 4;
bool exist[N][N][N_ARAH];

int n, X0, Y0, t;
pii arah[N_ARAH] = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};
queue<t4i> q[2];
bool visit[N][N][N_ARAH][N_D];
map<char, int> MAP;
int C[T + 5];
int D[T + 5];
int main() {
  
  MAP['E'] = 0;
  MAP['W'] = 1;
  MAP['N'] = 2;
  MAP['S'] = 3;
  
  ios::sync_with_stdio(false);
  cin >> n >> X0 >> Y0 >> t;
  for(int i = 0;i < n; ++i){
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;
    if(X1 > X2) swap(X1, X2);
    if(Y1 > Y2) swap(Y1, Y2);
    if(X1 == X2){
      for(int j = Y1; j < Y2; ++j) {
        exist[X1][j][2] = true;
        exist[X1][j + 1][3] = true;
        //cerr << "EXIST : " << X1 << " " << j << " 2" << endl;
       // cerr << "EXIST : " << X1 << " " << j + 1<< " 3" << endl;
      }
    }
    else if(Y1 == Y2){
      for(int j = X1; j < X2; ++j) {
        exist[j][Y1][0] = true;
        exist[j + 1][Y1][1] = true;
        //cerr << "EXIST : " << j << " " << Y1 << " 0" << endl;
        //cerr << "EXIST : " << j + 1 << " " << Y1 << " 1" << endl;
      }
    }
    else assert(false);
  }
  
  for(int i = 0 ;i < N_ARAH; ++i) {
    q[0].emplace(X0, Y0, i, 0);
    visit[X0][Y0][i][0] = true;
  }
  for(int i = 0;i < t; ++i){
    int times;
    char c;
    cin >> times >> c;
    D[i] = times;
    C[i] = MAP[c];
    //cerr << D[i] << " " << C[i] << endl;
  }
  
  for(int i = 0;i < t; ++i){
    while(!q[0].empty()){
      int X, Y, A, step;
      tie(X, Y, A, step) = q[0].front(); q[0].pop();
      //cerr << "TAHAP " << i << ": " << X << " " << Y << " " << A << " " << step << endl;
      if(step == D[i]) continue;
      if(i && step == 0 && A != C[i-1]){
        if((A ^ C[i-1]) == 1) continue;
        if(!exist[X][Y][C[i-1]]) continue;
        int x_now = X + arah[C[i-1]].fi;
        int y_now = Y + arah[C[i-1]].se;
        if(!visit[x_now][y_now][C[i-1]][step + 1]){
          visit[x_now][y_now][C[i-1]][step + 1] = true;
          q[0].emplace(x_now, y_now, C[i-1], step + 1);
        }
      }
      else{
        for(int j = 0; j < N_ARAH; ++j){
          if((j ^ A) == 1) continue; 
          if(!exist[X][Y][j]) continue;
          int x_now = X + arah[j].fi;
          int y_now = Y + arah[j].se;
          if(!visit[x_now][y_now][j][step + 1]){
            visit[x_now][y_now][j][step + 1] = true;
            q[0].emplace(x_now, y_now, j, step + 1);
          }
        }
      }
    }
    
    while(!q[1].empty()) q[1].pop();
    for(int j = 0;j < N; ++j){
      for(int k = 0;k < N; ++k){
        for(int l = 0;l < N_ARAH; ++l){
          if(visit[j][k][l][D[i]] && ((l ^ C[i]) != 1)) q[1].emplace(j, k, l, 0);
        }
      }
    }
    memset(visit, 0, sizeof visit);
    while(!q[1].empty()){
      int X, Y, A, step;
      tie(X, Y, A, step) = q[1].front(); q[1].pop();
      visit[X][Y][A][step] = true;
      q[0].emplace(X, Y, A, step);
    }
  }

  for(int i = 0;i < N; ++i){
    for(int j = 0;j < N; ++j){
      bool bisa = false;
      for(int k = 0;k < N_ARAH && !bisa; ++k){
        if(!visit[i][j][k][0]) continue;
        //cerr << "HAHA " << i << " " << j << " " << k << endl;
        if(k == C[t-1]) bisa = true;
        else if(exist[i][j][C[t-1]] && ((k ^ C[t-1]) != 1)) bisa = true;
      }
      if(bisa) cout << i << " " << j << endl;
    }
  }
  
  return 0;
}