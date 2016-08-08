#include <bits/stdc++.h>

using namespace std;

int to[256];
int dem[50][50], pos[50], sz[50], cnt[50];
string line;
queue<int> q[3];

int main() {
  to['m'] = to['k'] = to['b'] = 0;
  to['a'] = to['p'] = 1;
  to['h'] = 2;
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    printf("Kasus #%d\n", tc);
    int n;
    scanf("%d\n", &n);
    memset(cnt, 0, sizeof cnt);
    int sum = 0;
    for(int i = 0; i<n; i++) {
      getline(cin, line);
      pos[i] = sz[i] = 0;
      for(int j = 0; j<line.size(); j++)
        if(line[j] != ' ') {
          dem[i][sz[i]++] = to[line[j]];
          cnt[i]++;
          sum++;
        }
      q[dem[i][0]].push(i);
    }
    bool ok = true;
    while(ok) {
      ok = false;
      for(int i = 0; i<3; i++) {
        if(q[i].empty())
          continue;
        ok = true;
        int now = q[i].front(); q[i].pop();
        int ccnt = 5;
        while(ccnt-->0 || (sum == cnt[now] && cnt[now] > 0)) {
          if(pos[now] == sz[now])
            break;
          if(dem[now][pos[now]] == i)
            pos[now]++;
          else
            break;
          cnt[now]--;
          sum--;
        }
        if(pos[now] < sz[now])
          q[dem[now][pos[now]]].push(now);
        printf("Pembeli #%d\n", now+1);
      }
    }
  }
  
  return 0;
}