#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

char s[N];
char dir[] = "WASD";
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
int rmin[N], rmax[N], cmin[N], cmax[N];
int rpos[N], cpos[N];

int idx[256];

int main() {
  int t;
  for (int i = 0; i < 4; ++i)
    idx[dir[i]] = i;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    cpos[0] = rpos[0] = 0;
    cmin[0] = rmin[0] = 0;
    cmax[0] = rmax[0] = 0;
    for (int i = 0; i < n; ++i) {
      int cur = idx[s[i]];
      rpos[i+1] = rpos[i] + dr[cur];
      cpos[i+1] = cpos[i] + dc[cur];
      rmin[i+1] = min(rmin[i], rpos[i+1]);
      rmax[i+1] = max(rmax[i], rpos[i+1]);
      cmin[i+1] = min(cmin[i], cpos[i+1]);
      cmax[i+1] = max(cmax[i], cpos[i+1]);
    }
    cpos[n+1] = rpos[n+1] = 0;
    cmin[n+1] = rmin[n+1] = 0;
    cmax[n+1] = rmax[n+1] = 0;
    long long ans = 1e18;
    for (int i = n; i >= 0; --i) {
      for (int pil = 0; pil < 4; ++pil) {
        int rnow = rpos[i] + dr[pil];
        int cnow = cpos[i] + dc[pil];
        int rlow = rmin[i], rhig = rmax[i];
        int clow = cmin[i], chig = cmax[i];
        rlow = min(rlow, rnow);
        rhig = max(rhig, rnow);
        clow = min(clow, cnow);
        chig = max(chig, cnow);
        int offr = rnow - rpos[i+1];
        int offc = cnow - cpos[i+1];
        rlow = min(rlow, rmin[i+1] + offr);
        rhig = max(rhig, rmax[i+1] + offr);
        clow = min(clow, cmin[i+1] + offc);
        chig = max(chig, cmax[i+1] + offc);
        ans = min(ans, 1LL * (rhig - rlow + 1) * (chig - clow + 1));
      }
      if (i > 0) {
        int cur = idx[s[i-1]]^2;
        rpos[i] = rpos[i+1] + dr[cur];
        cpos[i] = cpos[i+1] + dc[cur];
        rmin[i] = min(rmin[i+1], rpos[i]);
        rmax[i] = max(rmax[i+1], rpos[i]);
        cmin[i] = min(cmin[i+1], cpos[i]);
        cmax[i] = max(cmax[i+1], cpos[i]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
