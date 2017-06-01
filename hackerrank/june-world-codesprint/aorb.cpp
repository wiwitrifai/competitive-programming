#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int to[257];
char hek[20];
pair<int, int> mi[17][17][17];
int cost[17][17][17];
char s[3][N];
int q, k, n[3];
pair<int, int> res[N];

int main() {
  for(int i = 0; i<= 9; i++) {
    to[i + '0'] = i;
    hek[i] = i+'0';
  }
  for(int i = 10; i<16; i++) {
    to['A'+i-10] = i;
    hek[i] = 'A'+i-10;
  }
  for(int i = 0; i<16; i++)
    for(int j = 0; j<16; j++)
      for(int k = 0; k<16; k++) {
        int ii = i, jj = j;
        int cs = 0;
        for(int l = 1; l<16; l<<=1)
          if(k & l) {
            if(((ii|jj) & l) == 0) {
              cs++;
              jj |= l;
            }
          }
          else {
            if(ii & l) {
              ii ^= l;
              cs++;
            }
            if(jj & l) {
              jj ^= l;
              cs++;
            }
          }
        mi[i][j][k] = make_pair(ii, jj);
        cost[i][j][k] = cs;
      }
  scanf("%d", &q);
  while(q--) {
    scanf("%d", &k);
    int ma = 0;
    for(int i = 0; i<3; i++) {
      scanf("%s", s[i]);
      n[i] = strlen(s[i]);
      ma = max(ma, n[i]);
      reverse(s[i], s[i]+n[i]);
    }
    for(int i = 0; i<3; i++) {
      for(int j = n[i]; j<ma; j++)
        s[i][j] = '0';
      s[i][ma] = '\0';
      reverse(s[i], s[i]+n[i]);
    }
    for(int i = 0; i<ma; i++) {
      int a = to[s[0][i]], b = to[s[1][i]], c = to[s[2][i]];
      res[i] = mi[a][b][c];
      k -= cost[a][b][c];
    }
    if(k < 0) {
      puts("-1");
      continue;
    }
    for(int i = 0; i<ma; i++) {
      if(k == 0)
        break;
      for(int j = 8; j>0; j>>=1)
        if(res[i].first & j & res[i].second) {
          if(k > 0) {
            res[i].first ^= j;
            k--;
          }
        }
        else if(res[i].first & j) {
          if(k > 1) {
            res[i].first ^= j;
            res[i].second ^= j;
            k -= 2;
          }
        }
    }
    int off = 0;
    while(off+1 < ma && res[off].first == 0) off++;
    for(int i = off; i<ma; i++)
      printf("%c", hek[res[i].first]);
    printf("\n");
    off = 0;
    while(off+1 < ma && res[off].second == 0) off++;
    for(int i = off; i<ma; i++)
      printf("%c", hek[res[i].second]);
    printf("\n");
  }

  
  return 0;
}