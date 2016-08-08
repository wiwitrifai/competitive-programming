#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int aa = a*a, bb = b*b, cc = c*c, ab = a+b, ac = a+c, bc = b+c;
    double ans1 = sqrt(min(min(ab * ab + cc, ac * ac + bb), bc * bc + aa));
    double ans2 = a + b + c;
    double ans3 = sqrt(aa + bb + cc);
    printf("%.9lf %.9lf %.9lf\n", ans1, ans2, ans3);
  }

  return 0;
}