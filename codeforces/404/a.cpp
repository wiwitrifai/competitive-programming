#include <bits/stdc++.h>

using namespace std;

string s[] = {"Tetrahedron", "Cube", "Octahedron", "Dodecahedron", "Icosahedron"};
int c[] = {4, 6, 8, 12, 20};

int main() {
  map< string, int > mp;
  for (int i = 0; i < 5; i++)
    mp[s[i]] = c[i];
  int n;
  scanf("%d", &n);
  int ans = 0;
  while (n--) {
    string str;
    cin >> str;
    ans += mp[str];
  }
  printf("%d\n", ans);
  return 0;
}