#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long x, y;
  cin >> x >> y;
  long long uprig, rig, down, downlef, lef, up;
  cin >> uprig >> rig >> down >> downlef >> lef >> up;
  for (int i = 0; i < 10; ++i) {
    uprig = min(uprig, up + rig);
    downlef = min(downlef, down + lef);
    up = min(up, uprig + lef);
    rig = min(rig, uprig + down);
    down = min(down, downlef + rig);
    lef = min(lef, downlef + up);
  }
  long long ans = 0;
  if (x > 0 && y > 0) {
    long long d = min(x, y);
    ans += d * uprig;
    x -= d;
    y -= d;
  }
  if (x < 0 && y < 0) {
    long long d = min(-x, -y);
    ans += d * downlef;
    x += d;
    y += d;
  }
  ans += max(x, 0LL) * up;
  ans += max(-x, 0LL) * down;
  ans += max(y, 0LL) * rig;
  ans += max(-y, 0LL) * lef;
  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
