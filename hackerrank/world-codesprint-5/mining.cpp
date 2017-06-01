#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int n, k, x[N], w[N];
long long dp[N][N], last[N][N];

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i<n; i++)  
    scanf("%d%d", x+i, w+i);
  // x[0] = x[1];
  x[n] = x[n-1];
  int s = 0;
  long long al = 0, ar = 0, sum = 0;
  memset(last, -1, sizeof last);
  for(int i = 0; i<n; i++) {
    sum += 1LL*(x[i] - x[s]) * w[i];
    ar += w[i]; 
    while(al+2*w[s] <= ar) {
      al += w[s];
      ar -= w[s];
      sum += (al-ar) * (x[s+1]-x[s]);
      s++;
    }
    dp[i][1] = sum;
    last[i][1] = s;
    // cerr << i << " 1 " << sum << " " << s << endl;
  }
  for(int i = 0; i<n-1; i++) {
    for(int j = 1; j<k; j++) if(last[i][j] >= 0) {
      al = 0;
      ar = 0;
      s = i+1;
      int low = (x[i+1] - x[last[i][j]]);
      long long bef = dp[i][j];
      // cerr << i << " " << j << endl;
      for(int c = i+1; c < n; c++) {
        bef += 1LL*(x[c]-x[s])*w[c];
        ar += w[c];
        while(al + 2*w[s] <= ar) {
          al += w[s];
          ar -= w[s];
          bef += (al-ar) * (x[s+1]-x[s]);
          s++;
        }
        if(x[s] - x[i+1] > low)
          break;
        if(last[c][j+1] == -1) {
          dp[c][j+1] = bef;
          last[c][j+1] = s;
        }
        else if(dp[c][j+1] >bef || (dp[c][j+1] == bef && last[c][j+1] > s)) {
          dp[c][j+1] = bef;
          last[c][j+1] = s;
        }
        // cerr << c << " " << j+1 << " " << s << " " <<   bef << endl;
      }
    }
  }
  printf("%lld\n", dp[n-1][k]);

  return 0;
}