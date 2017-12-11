
#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
int p[11], s[11];
int n;
pair<int, int> order[55];


bool cek1(vector<int> vp) {
  sort(vp.begin(), vp.end());
  bool ok = 1;
  int need = 0;
  for (int i = 0; i < n; ++i) {
    need += order[i].second;
    if (i + 1 < n && order[i].first == order[i+1].first) continue;
    int dish = 0, upper = 0;
    for (int j = 0; j <= i; ++j) {
      int z = i-j;
      if (z < vp.size())
        dish += order[j].first * vp[(int)vp.size()-1-z];
      upper += order[j].second;
      dish = min(dish, upper);
    }
    if (dish < need) {
      ok = 0;
      break;
    }
  }
  return ok;
}

typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
 
const DOUBLE EPS =1e-9;
 
struct LPSolver {
  int m, n;
  VI B, N;
  VVD D;
 
  LPSolver(const VVD &A,const VD &b,const VD &c):
      m(b.size()), n(c.size()), N(n+1), B(m), D(m+2, VD(n+2)){
    for(int i =0; i < m; i++)
      for(int j =0; j < n; j++) D[i][j]= A[i][j];
    for(int i =0; i < m; i++){
      B[i]= n+i; D[i][n]=-1; D[i][n+1]= b[i];
    }
    for(int j =0; j < n; j++){ N[j]= j; D[m][j]=-c[j];}
    N[n]=-1; D[m+1][n]=1;
  }
 
  void Pivot(int r,int s){
    for(int i =0; i < m+2; i++)if(i != r)
      for(int j =0; j < n+2; j++)if(j != s)
        D[i][j]-= D[r][j]* D[i][s]/ D[r][s];
    for(int j =0; j < n+2; j++)if(j != s) D[r][j]/= D[r][s];
    for(int i =0; i < m+2; i++)if(i != r) D[i][s]/=-D[r][s];
    D[r][s]=1.0/ D[r][s];
    swap(B[r], N[s]);
  }
 
  bool Simplex(int phase){
    int x = phase ==1? m+1: m;
    while(true){
      int s =-1;
      for(int j =0; j <= n; j++){
        if(phase ==2 && N[j]==-1)continue;
        if(s ==-1|| D[x][j]< D[x][s]|| D[x][j]== D[x][s]&& N[j]< N[s])
          s = j;
      }
      if(D[x][s]>=-EPS) return true;
      int r =-1;
      for(int i =0; i < m; i++){
        if(D[i][s]<=0)continue;
        if(r ==-1|| D[i][n+1]/ D[i][s]< D[r][n+1]/ D[r][s]||
          D[i][n+1]/ D[i][s]== D[r][n+1]/ D[r][s]&& B[i]< B[r])
          r = i;
      }
      if (r ==-1)return false;
      Pivot(r, s);
    }
  }
 
  DOUBLE Solve(VD &x){
    int r =0;
    for(int i =1; i < m; i++)if(D[i][n+1]< D[r][n+1]) r = i;
    if(D[r][n+1]<=-EPS){
      Pivot(r, n);
      if(!Simplex(1)||D[m+1][n+1]<-EPS)
        return-numeric_limits<DOUBLE>::infinity();
      for(int i =0; i < m; i++)if(B[i]==-1){
        int s =-1;
        for(int j =0; j <= n; j++)
          if(s ==-1|| D[i][j]< D[i][s]|| D[i][j]== D[i][s]&& N[j]< N[s])
            s = j;
        Pivot(i, s);
      }
    }
    if(!Simplex(2))return numeric_limits<DOUBLE>::infinity();
    x = VD(n);
    for(int i =0; i < m; i++)if(B[i]< n) x[B[i]]= D[i][n+1];
    return D[m][n+1];
  }
};

bool cek3(vector<int> vp) {
  VVD A;
  VD B;
  VD C(n * vp.size(), 1);
  int vn = vp.size() * n;
  for (int i = 0; i < vp.size(); ++i) {
    VD ineq(n * vp.size(), 0);
    for (int j = 0; j < n; ++j) {
      ineq[i * n + j] = 1;
      A.push_back(ineq);
      B.push_back(order[j].first);
    }
  }
  for (int i = 0; i < n; ++i) {
    VD ineq(n * vp.size(), 0);
    for (int j = 0; j < vp.size(); ++j) {
      ineq[j * n + i] = -(DOUBLE)vp[j];
    }
    A.push_back(ineq);
    B.push_back(-order[i].second);
  }
  LPSolver solver(A, B, C);
  VD x;
  DOUBLE ans = solver.Solve(x);
  // if (!isnan(ans) && !isinf(ans)) cerr << ans << endl;
  return !isnan(ans) && !isinf(ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
      scanf("%d %d", p+i, s+i);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int d, m;
      scanf("%d %d", &d, &m);
      order[i] = {m, d};
    }
    sort(order, order+n);
    int nmask = 1 << k;
    int ans = inf;
    vector<pair<int, int> > vmask;
    for (int mask = 1; mask < nmask; ++mask) {
      int tot = 0;
      for (int i = 0; i < k; ++i) {
        if (mask & (1 << i))
          tot += s[i];
      }
      vmask.emplace_back(tot, mask);
    }
    sort(vmask.begin(), vmask.end());
    for (auto it : vmask) {
      int mask = it.second;
      int tot = it.first;
      vector<int> vp;
      for (int i = 0; i < k; ++i) {
        if (mask & (1 << i)) {
          vp.push_back(p[i]);
        }
      }
      if (vp.size() > n) continue;
      // if (!cek1(vp)) continue;
      if (!cek3(vp)) continue;
      ans = min(ans, tot);
      break;
    }
    if (ans >= inf)
      ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}