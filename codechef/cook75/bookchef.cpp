#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool specials[N];

pair< pair<int, int >, string > posts[N];
char s[105];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    specials[x] = true;
  }
  for (int i = 0; i < m; i++) {
    int id, p;
    scanf("%d %d %s", &id, &p, s);
    posts[i] = {{id, p}, string(s)};
  }
  sort(posts, posts+m, [](pair< pair<int, int >, string > a, pair< pair<int, int >, string > b) {
    if (specials[a.first.first] != specials[b.first.first])
      return specials[a.first.first];
    return a.first.second > b.first.second;
  });
  for (int i = 0; i < m; i++) 
    printf("%s\n", posts[i].second.c_str());
  return 0;
}