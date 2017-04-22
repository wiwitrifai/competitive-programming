#include <bits/stdc++.h>

using namespace std;
const int N = 1024;
char s[N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int r, o, y, g, b, v;
    int n;
    scanf("%d %d %d %d %d %d %d", &n, &r, &o, &y, &g, &b, &v);
    int rr = r-g, yy = y-v, bb = b - o;
    bool ok = 1;
    if (rr < 0 || (rr == 0 && n > r+g && g > 0)) ok = 0;
    if (yy < 0 || (yy == 0 && n > y+v && v > 0)) ok = 0;
    if (bb < 0 || (bb == 0 && n > b+o && o > 0)) ok = 0;
    if (max(rr, max(yy, bb)) * 2 > rr + yy + bb) ok = 0;
    cerr << rr << " " << yy << " " << bb << endl;
    if (!ok) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    }
    else {
      printf("Case #%d: ", tc);
      if ((rr + yy + bb) == 0) {
        while (r-- > 0) printf("RG");
        while (y-- > 0) printf("YV");
        while (b-- > 0) printf("BO");
      }
      else {
        int last = -1, awal;
        int id = 0;
        while ((rr + yy + bb) > 0) {
          int ma = max(rr, max(yy, bb));
          pair< pair<int, int>, int > pp[] = {{{rr, awal == 0}, 0}, {{yy, awal == 1}, 1}, {{bb, awal == 2}, 2}};
          sort(pp, pp+3);
          int now = -1;
          if (pp[2].second == last)
            now = pp[1].second;
          else
            now = pp[2].second;
          if (last == -1)
            awal = now;
          last = now;
          if (last == 0)
            s[id] = 'R', rr--;
          else if (last == 1)
            s[id] = 'Y', yy--;
          else
            s[id] = 'B', bb--;
          id++;
        }
        bool yv = 0, rg = 0, bo = 0;
        for (int i = 0; i < id; i++) {
          printf("%c", s[i]);
          if (!rg && s[i] == 'R') {
            while (g-- > 0) printf("GR");
            rg = 1;
          }
          if (!yv && s[i] == 'Y') {
            while (v-- > 0) printf("VY");
            yv = 1;
          }
          if (!bo && s[i] == 'B') {
            while (o-- > 0) printf("OB");
            bo = 1;
          }
        }
      }
      printf("\n");
    }
    cerr << "Case #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}