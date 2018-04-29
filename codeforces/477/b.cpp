#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

pair<int, int> c[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i].first);
    c[i].second = i;
  }
  sort(c, c+n);
  for (int p = 0; p < n; ++p) {
    int now = c[p].first;
    int need = (a + now - 1) / now;
    // cerr << p << " " << need << " " << now << endl; 
    if (n-p > need) {
      int q = p+need;
      int nxt = c[q].first;
      int butuh = (b + nxt - 1) / nxt;
      // cerr << q << " wow " <<  butuh << " " << nxt << endl;
      if (q + butuh <= n) {
        vector<int> ans1, ans2;
        for (int i = 0; i < need; ++i)
          ans1.push_back(c[p+i].second);
        for (int i = 0; i < butuh; ++i)
          ans2.push_back(c[q+i].second);
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        puts("Yes");
        printf("%d %d\n", (int)ans1.size(), (int)ans2.size());
        for (int i = 0; i < (int)ans1.size(); ++i) {
          printf("%d%c", ans1[i]+1, i+1 == (int)ans1.size() ? '\n' : ' ');
        }
        for (int i = 0; i < (int)ans2.size(); ++i) {
          printf("%d%c", ans2[i]+1, i+1 == (int)ans2.size() ? '\n' : ' ');
        }
        return 0;
      }
    }
    now = c[p].first;
    need = (b + now - 1) / now;
    if (n-p > need) {
      int q = p+need;
      int nxt = c[q].first;
      int butuh = (a + nxt - 1) / nxt;
      if (q + butuh <= n) {
        vector<int> ans1, ans2;
        for (int i = 0; i < need; ++i)
          ans2.push_back(c[p+i].second);
        for (int i = 0; i < butuh; ++i)
          ans1.push_back(c[q+i].second);
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        puts("Yes");
        printf("%d %d\n", (int)ans1.size(), (int)ans2.size());
        for (int i = 0; i < (int)ans1.size(); ++i) {
          printf("%d%c", ans1[i]+1, i+1 == (int)ans1.size() ? '\n' : ' ');
        }
        for (int i = 0; i < (int)ans2.size(); ++i) {
          printf("%d%c", ans2[i]+1, i+1 == (int)ans2.size() ? '\n' : ' ');
        }
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}