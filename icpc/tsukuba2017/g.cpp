#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1), eps = 0.000845;

long double toRad(long double d) {
  return (long double) d * pi / 180;
}

int val[4][4] = {{1, 2, 4, 3}, {4, 2, 1, 3}, {4, 3, 1, 2}, {1, 3, 4, 2}};

int get(int d, long double l) {
  long double y = l * cos(toRad(fabs(d-30)));
  long double dy = (long double)0.5*sqrt((long double)3);
  int lantai = int (y/dy);
  // assert(int(y/dy + eps) == lantai); 
  // assert(int(y/dy - eps) == lantai); 
  long double sin120 = sin(toRad(120)), sind = sin(toRad(d)), sin60d = sin(toRad(60-d));
  int kanan = - int ((long double)l * sin60d / sin120) + int((long double)l * sind / sin120);
  // assert(int ((long double)l * sin60d / sin120) == int ((long double)l * sin60d / sin120 + eps));
  // assert(int ((long double)l * sin60d / sin120) == int ((long double)l * sin60d / sin120 - eps));
  // assert(int ((long double)l * sind / sin120) == int ((long double)l * sind / sin120 + eps));
  // assert(int ((long double)l * sind / sin120) == int ((long double)l * sind / sin120 - eps));
  kanan %= 4;
  if (kanan < 0) kanan += 4;
  // cerr << val[lantai % 4][kanan % 4] << endl;
  return val[lantai % 4][kanan % 4];
}

int kanan(int v) {
  if (v == 4) return 4;
  if (v == 1) return 2;
  if (v == 2) return 3;
  if (v == 3) return 1;
  assert(false);
}

string s, t;
int a, b;
long double x, y;

int main() {
  cin >> s >> a >> x;
  cin >> t >> b >> y;
  int le = get(a, x), ri = get(b, y);
  if (s != t) {
    if (s[1] == t[0])
      ri = kanan(ri);
    else
      le = kanan(le);
  }
  puts(le == ri ? "YES" : "NO");

  return 0;
}