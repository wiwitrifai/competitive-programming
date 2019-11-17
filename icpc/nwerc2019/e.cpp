#include <bits/stdc++.h>

using namespace std;

int f[10], g[10];

int main() {
  for (int i = 0; i < 5; ++i) {
    double x;
    scanf("%lf", &x);
    x *= 100;
    f[i] = int(x + 0.5);
  }
  sort(f, f+4);
  int best = 0, worst = 0;
  for (int i = 0; i < 3; ++i) {
    best += f[i];
    worst += f[i+1];
  }
  int target = f[4] * 3;
  if (target < best)
    puts("impossible");
  else if (target >= worst)
    puts("infinite");
  else {
    vector<int> cand;
    for (int i = 0; i < 4; ++i)
      for (int j = i+1; j < 4; ++j) {
        int cur = target - f[i] - f[j];
        if (cur < 0) continue;
        cand.push_back(cur);
      }
    sort(cand.begin(), cand.end());
    int answer = f[0];
    for (int x : cand) {
      for (int i = 0; i < 4; ++i) {
        g[i] = f[i];
      }
      g[4] = x;
      sort(g, g+5);
      int cur = g[1] + g[2] + g[3];
      if (cur <= target) {
        answer = max(answer, x);
      }
    }
    printf("%d.%02d\n", answer/100, answer % 100);
  }
  return 0;
}
