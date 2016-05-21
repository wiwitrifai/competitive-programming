#include <bits/stdc++.h>

using namespace std;

const int N = 1<<19;

int n;
pair<int, int> a[2][N];
int m[2], ma;

int main() {
  freopen("262144.in", "r", stdin);
  freopen("262144.out", "w", stdout);
  scanf("%d", &n);
  ma = 0;
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    a[0][i] = make_pair(x, 1);
    ma = max(ma, x);
  }
  m[0] = n;
  bool cont = false;
  for(int i = 1; i<=ma; i++) {
    int d = i&1, c = d^1;
    int &now = m[d];
    now = 0;
    int cnt = 0, last = 0;
    for(int j = 0; j<m[c]; j++) {
      if(i == a[c][j].first)
        cnt += a[c][j].second;
      else {
        if(cnt) {
          if(cnt > 1) {
            a[d][now++] = make_pair(i+1, cnt/2);
            if(i == ma)
              ma++;
          }
          if(cnt & 1) {
            a[d][now++] = make_pair(1, 1);
            if(cnt > 1)
              a[d][now++] = make_pair(i+1, cnt/2);
          }
          cnt = 0;
        }
        if(a[c][j].first > i)
          a[d][now++] = a[c][j];
        else if(last >= i)
          a[d][now++] = make_pair(1, 1);
      }
      last = a[c][j].first;
    }
    if(cnt) {
      if(cnt > 1) {
        a[d][now++] = make_pair(i+1, cnt/2);
        if(i == ma)
          ma++;
      }
      if(cnt & 1) {
        a[d][now++] = make_pair(1, 1);
        if(cnt > 1)
          a[d][now++] = make_pair(i+1, cnt/2);
      }
      cnt = 0;
    }
  }
  cout << ma << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}