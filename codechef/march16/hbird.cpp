#include <bits/stdc++.h>

using namespace std;

const int N = 340, M = 112230;

int n, m;
vector< int > sumi[N], sumd[N], sum[N], h[N];
vector< long long > subi[N], subd[N], sub[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    h[i].resize(m);
    sum[i].resize(m);
    sumi[i].resize(m);
    sumd[i].resize(m);
    sub[i].resize(m);
    subi[i].resize(m);
    subd[i].resize(m);
  }
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++)
      scanf("%d", &h[i][j]);
  }
  for(int i = 0; i<m; i++) {
    int add = (i>0) ? sum[0][i-1] : 0;
    sum[0][i] = sub[0][i] = sumi[0][i] = subi[0][i] = add + h[0][i]; 
  }
  for(int i = 1; i<n; i++) {
    int bef = 0;
    for(int j = 0; j<m; j++) {
      bef += h[i][j];
      int adm = sum[i-1][j];
      int admi = (j > 0) ? sumi[i-1][j-1] : 0;
      long long adb = sub[i-1][j];
      long long adbi = (j > 0) ? subi[i-1][j-1] : 0;
      sum[i][j] = adm + bef;
      sumi[i][j] = admi + bef;
      adb[i][j] = adb + bef*(i+1);
      adbi[i][j] = adbi + bef*(i+1);
    }
  }
  int bef = 0;
  for(int i = 0; i<m; i++) {
    bef += h[n-1]i];
    sumd[n-1][i] = subd[n-1][i] = bef; 
  }
  for(int i = n-2; i>= 0; i--) {
    int bef = 0;
    for(int j = 0; j<m; j++) {
      bef += h[i][j];
      int admd = (j > 0) ? sumd[i+1][j-1] : 0;
      long long adbd = (j > 0) ? subd[i+1][j-1] : 0;
      sumd[i][j] = admd + bef;
      adbd[i][j] = adbd + bef*(i+1);
    }
  }

  return 0;
}