#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int r[N], mi[N], ma[N], tim[N], rated[N], color[N];
bool wait[N];

char rateds[N], colors[N];

bool match(int i, int j) {
  if (!(mi[j] <= r[i] && r[i] <= ma[j])) return false;
  if (!(mi[i] <= r[j] && r[j] <= ma[i])) return false;
  if (tim[i] != tim[j]) return false;
  if (rated[i] != rated[j]) return false;
  if (color[i] == 0 && color[j] == 0) return true;
  if (color[i] == 0 || color[j] == 0) return false;
  return (color[i] != color[j]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d %s %s", r+i, mi+i, ma+i, tim+i, rateds, colors);
      rated[i] = (rateds[0] == 'r');
      color[i] = (colors[0] == 'r' ? 0 : (colors[0] == 'w' ? 1 : 2));
      // cerr << i << " " << r[i] << " " << mi[i] << " " << ma[i] << " " << tim[i] << " " << rated[i] << " " << color[i] << endl;
      int ans = -1;
      for (int j = 0; j < i; j++) {
        if (!wait[j]) continue;
        // cerr << i << " " << j << " " << match(i, j) << endl;
        if (match(i, j)) {
          ans = j;
          break;
        }
      }
      if (ans == -1) {
        wait[i] = 1;
        puts("wait");
      }
      else {
        wait[i] = wait[ans] = 0;
        printf("%d\n", ans+1);
      }
    }
  }
  return 0;
}