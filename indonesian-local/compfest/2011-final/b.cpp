#include <bits/stdc++.h>

using namespace std;

const int N = 500;

int cnt[N];
char a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 10; i++)
      scanf("%d", cnt+i);
    string le = "", ri = "";
    while (1) {
      if (cnt[9] > 0 && cnt[6] > 0) {
        le.push_back('9');
        ri.push_back('6');
        cnt[9]--; cnt[6]--;
      }
      else if (cnt[8] > 1) {
        le.push_back('8');
        ri.push_back('8');
        cnt[8] -= 2;
      }
      else if (cnt[1] > 1) {
        le.push_back('1');
        ri.push_back('1');
        cnt[1] -= 2;
      }
      else if (cnt[0] > 1) {
        le.push_back('0');
        ri.push_back('0');
        cnt[0] -= 2;
      }
      else
        break;
    }
    if (cnt[8] > 0)
      le.push_back('8');
    else if (cnt[1] > 0)
      le.push_back('1');
    else if (cnt[0] > 0)
      le.push_back('0');
    reverse(ri.begin(), ri.end());
    string ans = le + ri;
    if (ans.empty() || ans[0] == '0') {
      puts("-1");
      continue;
    }
    cout << ans << endl;
  }
  return 0;
}