#include <bits/stdc++.h>

using namespace std;

const long long base = 1e6;

long long getL() {
  long long a, b;
  scanf("%lld.%lld", &a, &b);
  return a * base + b;
}

void printL(long long a) {
  printf("%lld.%06lld", a/base, a % base);
}

typedef pair<long long , long long> point;

long long cross(point p, point q, point r) {
  return (p.first - q.first) * (r.second - q.second) - (p.second - q.second) * (r.first - q.first);
}

pair<long long, long long> p[3];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 3; i++) {
      p[i].first = getL();
      p[i].second = getL();
    }
    if (p[0] == p[1] && p[1] == p[2]) {
      printL(p[0].first);
      printf(" ");
      printL(p[0].second);
      printf("\n");
    }
    else if (cross(p[0], p[1], p[2]) == 0) {
      vector<pair<point, int> > s;
      for (int i = 0; i < 3; i++)
        s.push_back(make_pair(p[i], i));
      sort(s.begin(), s.end());
      pair<point, int> sa = s[0];
      pair<point, int> sb = s[2];
      if (sa.second > sb.second) {
        swap(sa, sb);
      }
      p[0] = sa.first;
      p[1] = sb.first;
      printL(p[0].first);
      printf(" ");
      printL(p[0].second);
      printf("\t");
      printL(p[1].first);
      printf(" ");
      printL(p[1].second);
      printf("\n");
    }
    else {
      for (int i = 0; i < 3; i++) {
        printL(p[i].first);
        printf(" ");
        printL(p[i].second);
        printf("%c", i == 2 ? '\n' : '\t');        
      }
    }
  }
  return 0;
}