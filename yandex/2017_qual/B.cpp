#include <bits/stdc++.h>

using namespace std;

int n;
string room[17][25], name;
string city[17], s;
map< string, int > mp;
int need[100];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int r;
    cin >> city[i] >> r;
    mp[city[i]] = i;
    for (int j = 0; j < r; j++) {
      cin >> s >> name;
      for (int k = 0; k < s.size(); k++)
        if (s[k] == '.')
          room[i][k] = name;
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int c;
    scanf("%d", &c);
    for (int j = 0; j < c; j++) {
      cin >> name;
      need[j] = mp[name];
    }
    int ans = 0;
    while (ans < 24) {
      bool ok = 1;
      for (int j = 0; j < c; j++) {
        if (room[need[j]][ans].empty())
          ok = 0;
      }
      if (ok) break;
      ans++;
    }
    if (ans >= 24)
      puts("No");
    else {
      printf("Yes ");
      for (int j = 0; j < c; j++)
        printf(" %s", room[need[j]][ans].c_str());
      printf("  \n");
    }
  }

  return 0;
}