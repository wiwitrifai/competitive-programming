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

typedef long double LD;

struct point {
  LD x, y, z;
  point(LD x = 0, LD y = 0, LD z = 0) : x(x), y(y), z(z) {}
  point operator+(point p) { return point(x+p.x, y+p.y, z+p.z); }
  point operator-(point p) { return point(x-p.x, y-p.y, z-p.z); }
  point operator%(point p) { return point(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x); } 
  point operator*(LD s) { return point(x * s, y * s, z * s); }
  point operator/(LD s) { return point(x / s, y / s, z / s); }
  LD operator*(point p) { return x * p.x + y * p.y + z * p.z; }
  LD norm() { return sqrt(*this * *this); }
};

ostream& operator<<(ostream & os, point p) {
  return os << "(" << p.x << "," << p.y << "," << p.z << ")";
}

void read(point & p) {
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);
  p = point(x, y, z); 
}

int main() {
  open_file("jupiter.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    point n, a;
    read(n);
    read(a);
    int l, h;
    scanf("%d %d", &l, &h);
    n = n / n.norm();
    point m = n % a;
    point b = m * sqrt(3) * 0.5 - a * 0.5;
    point c = point() - m * sqrt(3) * 0.5 - a * 0.5;
    point base(0, 0, -h);
    printf("%.6lf %.6lf %.6lf\n", (double)(base - a).norm(), (double)(base - b).norm(), (double)(base - c).norm());
  }
  close_file();
  return 0;
}