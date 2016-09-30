#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 +5 ;

int to[256], cnt[27];

vector < pair<char, int > > decom;

int id[27][N], p[27];
char ans[N], s[N];
int st[N], nx[N];

int main() {
  for (int i = 'A'; i <= 'Z'; i++)
    to[i] = i - 'A' + 1;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int cur = 0;
    char last = s[0];
    decom.clear();
    for (int i = 1; i < n; i++) {
      if (s[i] < '0' || s[i] > '9') {
        cur = max(cur, 1);
        decom.push_back({last, cur});
        cur = 0;
        last = s[i];
      }
      else {
        cur = cur * 10 + s[i] - '0';
      }
    }
    cur = max(cur, 1);
    decom.push_back({last, cur});
    memset(p, 0, sizeof p);
    n = 0;
    for (int i = 0; i < decom.size(); i++) {
      int now = to[decom[i].first];
      cur = decom[i].second;
      cnt[now] += cur;
      while (cur--) {
        id[now][p[now]++] = n;
        st[n++] = now;
      }
    }
    memset(p, 0, sizeof p);
    int now = 0;
    for (int i = 0; i < n; i++) {
      while (!cnt[now])
        now++;
      cnt[now]--;
      nx[i] = id[now][p[now]++];
    }
    now = nx[id[0][0]];
    while (st[now]) {
      printf("%c", st[now] + 'A' - 1);
      now = nx[now];
    }
    printf(".\n");
  }
  return 0;
}