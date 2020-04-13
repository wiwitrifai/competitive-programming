#include <bits/stdc++.h>

using namespace std;

// vector<int> val;
// set<int> st;
// int a = 1;

// void gen(int n) {
//   for (; (int)val.size() < n; ++a) {
//     if (st.count(a)) {
//       continue;
//     }
//     int b = a+1;
//     while (st.count(b) || st.count(b^a)) ++b;
//     st.insert(a);
//     st.insert(b);
//     st.insert(a^b);
//     val.emplace_back(a);
//     val.emplace_back(b);
//     val.emplace_back(a^b);
//   }
// }

int add[2][4] = {{0, 2, 3, 1}, {0, 3, 1, 2}};

long long solve(long long n) {
  long long level = 1;
  while (level * 4 <= n)
    level *= 4;
  long long pos = n - level;
  if (pos % 3 == 0) {
    return level + (pos / 3);
  }
  if (pos % 3 == 1) {
    long long ans = level * 2;
    vector<int> dig;
    pos /= 3;
    long long now = level/4;
    while (now) {
      now /= 4;
      dig.push_back(pos % 4);
      pos /= 4;
    }
    reverse(dig.begin(), dig.end());
    for (int x : dig) {
      level /= 4;
      ans += level * add[0][x];
    }
    return ans;
  }
  else {
    long long ans = level * 3;
    vector<int> dig;
    pos /= 3;
    long long now = level/4;
    while (now) {
      now /= 4;
      dig.push_back(pos % 4);
      pos /= 4;
    }
    reverse(dig.begin(), dig.end());
    for (int x : dig) {
      level /= 4;
      ans += level * add[1][x];
    }
    return ans;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
  }
  return 0;
}
