#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

const int N = 1e5 + 5;
map<string, tuple<int, int, int> > coffee;
char buffer[3][55];

int main() {
  open_file("coffee.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    coffee.clear();
    int c, p;
    scanf("%d %d", &c, &p);
    for (int i = 0; i < c; ++i) {
      int s, m, l;
      scanf("%s %d %d %d", buffer[0], &s, &m, &l);
      coffee[buffer[0]] = make_tuple(s, m, l);
    }
    int delivery = 100 / p;
    for (int i = 0; i < p; ++i) {
      for (int j = 0; j < 3; ++j)
        scanf("%s", buffer[j]);
      int s, m, l;
      tie(s, m, l) = coffee[buffer[2]];
      int ans = 0;
      if (buffer[1][0] == 's')
        ans = s;
      else if (buffer[1][0] == 'm')
        ans = m;
      else if (buffer[1][0] == 'l')
        ans = l;
      else
        assert(false);
      ans += delivery;
      if (ans % 5 == 1)
        --ans;
      else if (ans % 5 == 4)
        ++ans;
      printf("%s %d\n", buffer[0], ans);
    }
  }
  close_file();
  return 0;
}