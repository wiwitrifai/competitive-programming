#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, m, k;
char arr[N + 2][N + 2];
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

pii arah[8] = {mp(0,-1), mp(-1,-1), mp(-1,0),mp(-1,1),mp(0,1),mp(1,1),mp(1,0),mp(1,-1)};

struct grid{
  char ar[N + 2][N + 2];

  grid(){
    memset(ar, 0, sizeof ar);
  } 

  grid& operator=(const grid& g){
    for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j){
      this->ar[i][j] = g.ar[i][j];
    }
    return (*this);
  }

  bool operator<(const grid& g) const{
    for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        if(this->ar[i][j] != g.ar[i][j]) return this->ar[i][j] < g.ar[i][j];
      }
    }
    return false;
  }

  bool operator>(const grid& g) const{
    for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        if(this->ar[i][j] != g.ar[i][j]) return this->ar[i][j] > g.ar[i][j];
      }
    }
    return false;
  }

  bool operator==(const grid& g) const{
     for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        if(this->ar[i][j] != g.ar[i][j]) return false;
      }
    }
    return true;
  }
} awal;

vector<grid> ve;
map<grid, int> MAP;
bool valid(int x, int y){
  return x >= 0 && y >= 0 && x < n && y < m;
}
int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0;i < n; ++i) {
    scanf("%s", arr[i]);
    for(int j = 0;j < m; ++j) awal.ar[i][j] = arr[i][j];
  }
  ve.push_back(awal);
  MAP[awal] = 0;
  int idx = 1;
  int lastcycle = -1;

  for(idx = 0;idx < k && lastcycle == -1; ++idx){
    grid G;
    for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j){
      bool dead = ve[idx].ar[i][j] == '-';
      int life = 0, death = 0;
      for(int x = 0;x < 8; ++x){
        pii tmp = mp(i + arah[x].fi, j + arah[x].se);
        if(tmp.fi < 0) tmp.fi += n;
        else if(tmp.fi >= n) tmp.fi -= n;

        if(tmp.se < 0) tmp.se += m;
        else if(tmp.se >= m) tmp.se -= m; 

        if(ve[idx].ar[tmp.fi][tmp.se] == '*') life++;
        else death++;
      }
      if(dead){
        G.ar[i][j] = (life == 3) ? '*' : '-';
      }
      else{
        G.ar[i][j] = (life >= 2 && life <= 3) ? '*' : '-';
      }
    }

    if(MAP.count(G)){
      lastcycle = MAP[G];
    }
    else{
      MAP[G] = idx + 1;
      ve.push_back(G);
    }
  }

  grid ans;
  if(lastcycle == -1){
    ans = ve[k];
  }
  else{
    int siklus = idx - lastcycle;

    int sisa = (k - idx) % siklus;
    ans = ve[lastcycle + sisa];
  }
  for(int i = 0;i < n; ++i) {
    for(int j = 0;j < m; ++j){
      printf("%c", ans.ar[i][j]);
    }
    puts("");
  }
  return 0;
}