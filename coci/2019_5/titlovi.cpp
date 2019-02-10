#include <bits/stdc++.h>

using namespace std;

struct block {
  int k;
  int start, end;
  vector<string> str;
  int read() {
    if (scanf("%d", &k) != 1)
      return 2;
    int a, b, c, d;
    int e, f, g, h;
    scanf("%d:%d:%d,%d --> %d:%d:%d,%d\n", &a, &b, &c, &d, &e, &f, &g, &h);
    start = ((a * 60 + b) * 60 + c) * 1000 + d;
    end = ((e * 60 + f) * 60 + g) * 1000 + h;
    string buffer;
    while (getline(cin, buffer)) {
      if (buffer[0] == '#')
        return 1;
      if (buffer.empty()) break;
      str.push_back(buffer);
    }
    return 0;
  }
};

void print_time(int x) {
  int t = x % 1000; x /= 1000;
  int s = x % 60; x /= 60;
  int m = x % 60; x /= 60;
  printf("%02d:%02d:%02d,%03d", x, m, s, t);
}


int main() {
  vector<block> vb;
  while (1) {
    block b;
    int res = b.read();
    if (res == 2)
      break;
    vb.push_back(b);
    if (res)
      break;
  }
  int v;
  scanf("%d", &v);
  for (int i = 0; i < vb.size(); ++i) {
    block b = vb[i];
    printf("%d\n", b.k);
    print_time(b.start + v);
    printf(" --> ");
    print_time(b.end + v);
    printf("\n");
    for (string s : b.str) {
      printf("%s\n", s.c_str());
    }
    printf((i+1 == vb.size()) ? "#\n" : "\n"); 
  }
  return 0;
}