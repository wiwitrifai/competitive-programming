#include <bits/stdc++.h>

using namespace std;

int p, tt, thres;
long double r;
int sm[50], su[50], ss[50];
long double val[4];
vector< int > ans[4];
void solve(int t, int sisa) {
  if(tt == t) {
    if(sisa)
      return;
    long double all = 0;
    long double rr = p;
    for(int i = 0; i<tt; i++) {
      rr *= (100.0 + r)/10000.0;
      long double now = 1.0 * rr * ss[i];
      // cerr << now << ", ";
      all += now;
      rr *= (100 - ss[i]);
    }
    // for(int i = 0; i<t; i++)
    //   printf("%d ", ss[i]);
    // printf("-%lf\n", all);
    for(int i = 0; i<3; i++) if(all > val[i]) {
      for(int j = 2; j>i; j--) {
        val[j] = val[j-1];
        ans[j] = ans[j-1];
      }
      val[i] = all;
      ans[i].clear();
      for(int j = 0; j<tt; j++)
        ans[i].push_back(ss[j]);
      break;
    }
  }
  else {
    int up = min(sm[t] + sisa, su[t]);
    for(ss[t] = sm[t]; ss[t] <= up; ss[t]++)
      solve(t+1, sisa - ss[t] + sm[t]);
  }
}
int main() {
  cin >> p >> r >> tt >> thres;
  int add = 0;
  for(int i = 0; i<tt; i++) {
    cin >> su[i];
    ss[i] = su[i];
    sm[i] = max(su[i]-thres, 0);
    add += su[i] - sm[i];
    su[i] = min(su[i]+thres, 99);
  }
  for(int i = 0; i<4; i++)
    val[i] = 0;
  long double all = 0;
  long double rr = p;
  for(int i = 0; i<tt; i++) {
    rr *= (100.0 + r)/10000.0;
    long double now = 1.0 * rr * ss[i];
    // cerr << now << ", ";
    all += now;
    rr *= (100 - ss[i]);
  }
  printf("%.3lf\n", (double)all);
  solve(0, add);
  for(int i = 0; i<3; i++) {
    printf("%.3lf -", (double)val[i]);
    for(int j = 0; j<ans[i].size(); j++)
      printf(" %d", ans[i][j]);
    printf("\n");
  }
  return 0;
}