/**
  IEEExtreme Programming Contest 10
  Problem : Playing 20 Questions with an Unreliable Friend
  Solver  : Wiwit Rifa'i
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 22;

vector< pair<int, int> > cnt[N];
vector< pair<int, int> > color[N];
int ty[N];
bool result[N], succ[N];
int col[11], to[256], cntcol[5];
int ans[11];

int main() {
  to['r'] = 0;
  to['g'] = 1;
  to['b'] = 2;
  int t;
  scanf("%d", &t);
  while (t--) {
    int q, n;
    scanf("%d %d%*c", &q, &n);
    for (int i = 0; i < q; i++) {
      cnt[i].clear();
      color[i].clear();
      ty[i] = 0;
      string s;
      int val;
      while (1) {
        cin >> s;
        if (s == "yes" || s == "no") {
          result[i] = (s == "yes");
          break;
        }
        else if (s == "and")
          ty[i] = 1;
        else if (s == "or")
          ty[i] = 0;
        else if (s == "color") {
          cin >> val >> s;
          color[i].push_back(make_pair(val-1, to[s[0]]));
        } 
        else {
          cin >> s >> val;
          cnt[i].push_back(make_pair(to[s[0]], val));
        }
      }
      // cerr << i << " " << ty[i] << " " << result[i] << endl;
      // for (auto it : cnt[i])
      //   cerr << it.first << " cnt " << it.second << endl;
      // for (auto it : color[i])
      //   cerr << it.first << " color " << it.second << endl;
    }
    for (int i = 0; i < 10; i++) {
      ans[i] = 0;
      // cerr << col[i] << " ";
    }
    int all = 1;
    for (int i = 0; i < 10; i++)
      all *= 3;
    int found = -1;
    for (int i = 0; i < all; i++) {
      int now = i;
      cntcol[0] = cntcol[1] = cntcol[2] = 0;
      for (int j = 0; j < 10; j++) {
        col[j] = now % 3;
        cntcol[col[j]]++;
        now /= 3;
      }
      int nfail = 0;
      for (int j = 0; j < q; j++) {
        bool ok = true;
        if (ty[j] == 0) {
          ok = false;
          for (auto it : cnt[j]) {
            if (cntcol[it.first] == it.second) {
              ok = true;
              break;
            }
          }
          for (auto it : color[j]) {
            ok |= col[it.first] == it.second;
            if (ok) {
              break;
            }
          }
        }
        else {
          ok = true;
          for (auto it : cnt[j]) {
            if (cntcol[it.first] != it.second) {
              ok = false;
              break;
            }
          }
          for (auto it : color[j]) {
            ok &= col[it.first] == it.second;
            if (!ok) {
              break;
            }
          }
        }
        if (result[j] == 0)
          ok = !ok;
        succ[j] = ok;
        nfail += !ok;
      }
      if (nfail == n) {
        for (int j = 0; j < 10; j++) {
          ans[j] |= (1<<col[j]);
        }
      }
    }
    for (int i = 0; i < 10; i++) {
      int k = 0;
      if (i)
        printf(" ");
      if (ans[i] & 1)
        printf("r"), k++;
      if (ans[i] & 2)
        printf("g"), k++;
      if (ans[i] & 4)
        printf("b"), k++;
    }
    printf("\n");
  }
  return 0;
}