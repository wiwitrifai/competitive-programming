/*
  iafir
  GCJ2016 Round 1A Problem B
  -Accepted-
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 2600;
int cnt[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for(int tc = 1; tc <= tt; tc++) {
    int n;
    scanf("%d", &n);
    printf("Case #%d:", tc);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i<2*n-1; i++) {
      for(int j = 0; j<n; j++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
      }
    }
    int hwa = 0;
    for(int i = 0; i<N; i++)
      if(cnt[i] & 1) {
        hwa++;
        printf(" %d", i);
      }
    assert(hwa == n);
    printf("\n");
    cerr << "Case #"<<tc << " Done" << endl;
  }
  return 0;
}