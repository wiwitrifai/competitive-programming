#include <bits/stdc++.h>

using namespace std;
typedef vector < int > vi;

int n, len[105], num[26];
vi al[26], topsort;
char s[105][105];
bool vis[26][26];

void die() {
  puts("Impossible");
  exit(0);
}

void dfs(int v) {
  num[v] = 0;
  for(int i = 0; i<al[v].size(); i++) {
    int u = al[v][i];
    if(num[u] == 0)
      die();
    if(num[u] == -1)
      dfs(u);
  }
  num[v] = 1;
  topsort.push_back(v);
}

int main()  {
#ifdef DEBUG
  time_t startt = clock();
#endif
  scanf("%d%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%s", s+i);
    len[i] = strlen(s[i]);
  } 
  n--;
  memset(vis, true, sizeof vis);
  for(int i = 0; i<n; i++) {
    int m = 0;
    while(s[i][m] == s[i+1][m]) m++;
    if(m < len[i] && m < len[i+1]) {
      int from = s[i][m]-'a', to = s[i+1][m]-'a';
      al[to].push_back(from);
    }
    else if(len[i] > len[i+1])
      die();
  }
  memset(num, -1, sizeof num);
  for(int i = 0; i<26; i++)
    if(num[i] == -1)
      dfs(i);
  for(int i = 0; i<topsort.size(); i++)
    printf("%c", topsort[i]+'a');
  puts("");
#ifdef DEBUG
  cerr << "Running time  : " << (double)(clock()-startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  int T = time(NULL)-1491365144;
  cerr << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
#endif
  return 0;
}