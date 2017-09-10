#include <bits/stdc++.h>

using namespace std;

string ori[][7] = {
{
"xxxxx",
"x...x",
"x...x",
"x...x",
"x...x",
"x...x",
"xxxxx"
},
{
"....x",
"....x",
"....x",
"....x",
"....x",
"....x",
"....x"
},
{
"xxxxx",
"....x",
"....x",
"xxxxx",
"x....",
"x....",
"xxxxx"
},
{
"xxxxx",
"....x",
"....x",
"xxxxx",
"....x",
"....x",
"xxxxx"
},
{
"x...x",
"x...x",
"x...x",
"xxxxx",
"....x",
"....x",
"....x"
},
{
"xxxxx",
"x....",
"x....",
"xxxxx",
"....x",
"....x",
"xxxxx"
},
{
"xxxxx",
"x....",
"x....",
"xxxxx",
"x...x",
"x...x",
"xxxxx"
},
{
"xxxxx",
"....x",
"....x",
"....x",
"....x",
"....x",
"....x"
},
{
"xxxxx",
"x...x",
"x...x",
"xxxxx",
"x...x",
"x...x",
"xxxxx"
},
{
"xxxxx",
"x...x",
"x...x",
"xxxxx",
"....x",
"....x",
"xxxxx"
}

};

const int N = 1e5 + 5;

char s[7][N];

int main() {
  for (int i = 0; i < 7; i++) {
    scanf("%s", s + i);
  }
  int n = 7;
  int m = strlen(s[0]);
  vector<int> num;
  for (int pos = 0; pos < m; pos += 6) {
    bool done = 0;
    for (int it = 0; it < 10; it++) {
      bool ok = 1;
      for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
          if (s[i][pos + j] != ori[it][i][j]) {
            ok = 0;
          }
        }
      }
      if (ok) {
        done = 1;
        num.push_back(it);
        break;
      }
    }
    if (!done) {
      num.push_back(-1);
    }
  }
  int a = 0, b = 0;
  bool udah = 0;
  for (int i = 0; i < num.size(); i++) {
    if (num[i] == -1) {
      udah = 1;
    } else {
      if (udah == 0) {
        a = a * 10 + num[i];
      } else {
        b = b * 10 + num[i];
      }
    }
  }
  int c = a + b;
  vector<int> ret;
  while (c) {
    ret.push_back(c % 10);
    c /= 10;
  }
  reverse(ret.begin(), ret.end());
  for (int i = 0; i < 7; i++) {
    for (int pos = 0; pos < ret.size(); pos++) {
      if (pos) printf(".");
      for (int j = 0; j < 5; j++) {
        printf("%c", ori[ret[pos]][i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}