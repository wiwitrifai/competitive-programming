// status: unfinished

#include <bits/stdc++.h>

using namespace std;

int limit;

string mirror(string s) {
  for (char & c : s) {
    if (c == 'L')
      c = 'R';
    else if (c == 'R')
      c = 'L';
  }
  return s;
}

string optimizestr(string ans) {
  string tmp = ans;
  ans.clear();
  for (char c : tmp) {
    if (c == 'L') {
      if (!ans.empty() && ans.back() == 'R') {
        ans.pop_back();
        continue;
      }
      int sz = ans.size();
      if (ans.size() > 1 && ans[sz-2] == 'L' && ans[sz-1] == 'L') {
        ans.pop_back();
        ans.back() = 'R';
        continue;
      }
    } else if (c == 'R') {
      if (!ans.empty() && ans.back() == 'L') {
        ans.pop_back();
        continue;
      }
      int sz = ans.size();
      if (ans.size() > 1 && ans[sz-2] == 'R' && ans[sz-1] == 'R') {
        ans.pop_back();
        ans.back() = 'L';
        continue;
      }
    }
    ans.push_back(c);
  }
  return ans;
}

string solve2(int n, int m, int lastn, int lastm, bool maxi);


string solve1(int n, int m, int lastn, int lastm, bool maxi) {
  cerr << "solve1 " << n << " " << m << " " << lastn << " " << lastm << " " << maxi << endl;
  string ans = "";
  if (n == 1) {
    assert(false);
    ans.push_back('L');
    for (int i = 0; i < m-1; ++i)
      ans.push_back('F');
    ans.push_back('R');
  } else if (m == 1) {
    for (int i = 0; i < m-1; ++i)
      ans.push_back('F');
  } else {
    ans.push_back('L');
    int d = min(lastn, n-1);
    string res;
    if (maxi) {
      d = min(19, n-1);
    } else {
      lastn = max(lastn-2, 1);
    }
    if ((d & 1) == 0)
      --d;
    res = solve2(m, d, lastm, lastn, true);
    res = mirror(res);
    ans += res;
    ans.push_back('R');
    ans.push_back('F');
    res = solve2(n-d, m, lastn, lastm, !maxi);
    res = mirror(res);
    ans += res;
  }
  return ans;
}

string solve2(int n, int m, int lastn, int lastm, bool maxi) {
  cerr << "solve2 " << n << " " << m << " " << lastn << " " << lastm << " " << maxi << endl;
  string ans = "";
  if (n == 1) {
    ans.push_back('L');
    for (int i = 0; i < m-1; ++i)
      ans.push_back('F');
    ans.push_back('R');
  } else if (m == 1) {
    for (int i = 0; i < m-1; ++i)
      ans.push_back('F');
  } else if (false) {
    // if (m & 1) {
    //   for (int i = 0; i < m/2; ++i) {
    //     ans += string(n-1, 'F');
    //     ans.push_back('L');
    //     ans.push_back('F');
    //     ans.push_back('L');
    //     ans += string(n-1, 'F');
    //     ans.push_back('R');
    //     ans.push_back('F');
    //     ans.push_back('R');
    //   }
    //   ans += string(n-1, 'F');
    // } else {
    //   ans.push_back('L');
    //   for (int i = 0; i < n/2; ++i) {
    //     ans += string(m-1, 'F');
    //     ans.push_back('R');
    //     ans.push_back('F');
    //     ans.push_back('R');
    //     ans += string(m-1, 'F');
    //     ans.push_back('L');
    //     ans.push_back('F');
    //     ans.push_back('L');
    //   }
    //   ans += string(m-1, 'F');
    //   ans.push_back('R');
    // }
  } else {
    ans.push_back('L');
    int d = min(lastn, n-1);
    string res;
    if (maxi) {
      d = min(19, n-1);
    } else {
      lastn = max(lastn-2, 1);
    }
    if ((d & 1) == 0)
      --d;
    res = solve2(m, d, lastm, 19, rand() & 1);
    res = mirror(res);
    ans += res;
    ans.push_back('R');
    ans.push_back('F');
    res = solve1(n-d, m, lastn, 19, !maxi);
    res = mirror(res);
    ans += res;
  }
  return ans;
}

string solve(int n, int m) {
  string ans = "FR";
  string res = solve1(n, m-1, 19, 19, true);
  ans += res;
  ans.push_back('R');
  ans.push_back('F');
  ans += string(m-1, 'F');
  ans.push_back('R');
  return optimizestr(ans);
}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

bool check(int n, int m, string & s) {
  int r = 0, c = 0;
  int dir = 1;
  vector<vector<bool>> is(n, vector<bool>(m, false));
  for (int ch : s) {
    if (ch == 'L')
      dir = (dir + 3) % 4;
    else if (ch == 'R')
      dir = (dir + 1) % 4;
    else {
      r += dr[dir];
      c += dc[dir];
      if (r < 0 || r >= n || c < 0 || c >= m)
        return false;
      if (is[r][c])
        return false;
      is[r][c] = true;
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!is[i][j])
        return false;
  return true;
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int s = 1;
  while (s * s <= max(n, m)) ++s;
  --s;
  limit = s * 20;
  string ans = solve(n, m);
  printf("%s\n", ans.c_str());
  assert(check(n, m, ans));
  for (int i = 0; i < (int)ans.size(); ++i) {
    for (int j = 1; j + limit <= (int)ans.size(); ++j) {
      // cerr << i << " " << j << " " << limit << endl;
      if (ans.substr(i, limit) == ans.substr(j, limit))
        cerr << i << " " << j << " " << ans.substr(i, limit) << " " << ans.substr(j, limit) << endl;
      assert(ans.substr(i, limit) != ans.substr(j, limit));
    }
  }
  return 0;
}
