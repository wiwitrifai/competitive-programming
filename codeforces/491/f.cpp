#include <bits/stdc++.h>

using namespace std;

vector<tuple<long long, long long, int> > cand;
vector<tuple<long long, long long, int> > ans;

int getLen(long long x) {
  int cnt = 0;
  while (x) {
    ++cnt;
    x /= 10;
  }
  return cnt;
}

long long conv(long long a, long long b, int c) {
  long long now = a;
  while (c--)
    now *= b;
  return now;
}

long long convt(tuple<long long, long long, int> t) {
  long long a, b;
  int c;
  tie(a, b, c) = t;
  return conv(a, b, c);
}

int calc(long long a, long long b, int c) {
  int cur = getLen(b);
  if (a != 1)
    cur += 1 + getLen(a);
  if (c != 1)
    cur += 1 + getLen(c);
  return cur;
}

int calct(tuple<long long, long long, int> t) {
  long long a, b;
  int c;
  tie(a, b, c) = t;  
  return calc(a, b, c);
}

void print(tuple<long long, long long, int> t) {
  long long a, b;
  int c;
  tie(a, b, c) = t;
  if (a != 1)
    cout << a << "*";
  cout << b;
  if (c != 1)
    cout << "^" << c;
}

int main() {
  long long n;
  cin >> n;
  for (long long b = 2; b * b <= n; ++b) {
    long long bb = b;
    for (int c = 1; bb <= n; bb *= b, ++c) {
      long long now = bb;
      for (long long a = 1; now <= n; now += bb, ++a) {
        int cur = calc(a, b, c);
        if (cur >= 6) break;
        if (cur >= getLen(conv(a, b, c))) continue;
        cand.emplace_back(a, b, c);
      }
    }
  }
  int best = getLen(n);
  ans.clear();
  ans.emplace_back(1, n, 1);
  for (int i = 0; i < cand.size(); ++i) {
    for (int j = i+1; j < cand.size(); ++j) {
      long long sum = convt(cand[i]) + convt(cand[j]);
      if (sum > n) continue;
      long long sisa = n - sum;
      int now = calct(cand[i]) + 1 + calct(cand[j]) + (sisa > 0 ? 1+getLen(sisa) : 0);
      if (now < best) {
        best = now;
        ans.clear();
        ans.push_back(cand[i]);
        ans.push_back(cand[j]);
        if (sisa > 0)
          ans.emplace_back(1, sisa, 1);
      }
    }
  }
  for (long long b = 2; b * b <= n; ++b) {
    long long bb = b;
    for (int c = 1; bb <= n; bb *= b, ++c) {
      long long now = bb;
      int cur = calc(1, b, c);
      if (cur >= best) break;
      long long a = 9;
      for (int d = 1; ; ++d) {
        a = a * 10 + 9;
        long long wow = conv(a, b, c);
        if (wow > n)
          break;
        long long sisa = n - wow;
        cur = calc(a, b, c);
        if (sisa > 0)
          cur += 1 + getLen(sisa);
        if (cur < best) {
          best = cur;
          ans.clear();
          ans.emplace_back(a, b, c);
          if (sisa > 0)
            ans.emplace_back(1, sisa, 1);
        }
      }
      a = n / bb;
      if (a <= 0) continue;
      long long sisa = n - conv(a, b, c);
      cur = calc(a, b, c) + (sisa > 0 ? 1 + getLen(sisa) : 0);
      if (cur < best) {
        best = cur;
        ans.clear();
        ans.emplace_back(a, b, c);
        if (sisa > 0)
          ans.emplace_back(1, sisa, 1);
      }
    }
  }
  print(ans[0]);
  for (int i = 1; i < ans.size(); ++i) {
    cout << "+";
    print(ans[i]);
  }
  cout << endl;
  return 0;
}