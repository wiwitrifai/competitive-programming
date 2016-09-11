#include <bits/stdc++.h>

using namespace std;

list< char > li;
char s[1000005];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    li.clear();
    scanf("%s", s);
    int n = strlen(s);
    li.push_front('#');
    auto it = li.begin();
    for (int i = 0; i < n; i++) {
      if (s[i] == '-') {
        if (it != li.begin()) {
          auto rm = it;
          it--;
          li.erase(rm);
        }
      }
      else if (s[i] == '<') {
        if (it != li.begin())
          it--;
      }
      else if (s[i] == '>') {
        it++;
        if (it == li.end())
          it--;
      }
      else {
        it++;
        li.insert(it, s[i]);
        it--;
      }
    }
    it = li.begin();
    for (it++; it != li.end(); it++) {
      printf("%c", *it);
    }
    printf("\n");
  }

  return 0;
}