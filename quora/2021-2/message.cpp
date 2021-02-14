#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
const long double eps = 1e-8;

double prob[N][N];
double cost[15];

double bef[N][N], aft[N][N];

int main() {
  string buffer;
  int n;
  cin >> n;
  vector<vector<int>> dataset;
  int m = 0;
  for (int i = 0; i < n; ++i) {
    while (getline(cin, buffer) && buffer.empty());
    stringstream ss(buffer);
    vector<int> s;
    int x;
    while (ss >> x) {
      s.push_back(x);
      m = max(m, x+1);
    }
    dataset.push_back(s);
  }
  cost[0] = 1;
  for (int i = 1; i < 15; ++i) {
    cost[i] = 1.0 / exp((long double)i * i / 0.5);
  }
  for (auto & s : dataset) {
    int len = s.size();
    for (int i = 0; i < len; ++i) {
      if (s[i] == -1) continue;
      for (int j = i+1; j < len; ++j) {
        if (s[j] == -1) continue;
        prob[s[i]][s[j]] += cost[j-i];
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    double tot = 0;
    for (int j = 0; j < m; ++j) {
      tot += prob[i][j];
    }
    if (tot < eps)
      tot = eps;
    for (int j = 0; j < m; ++j) {
      aft[i][j] = prob[i][j] / tot;
    }
    tot = 0;
    for (int j = 0; j < m; ++j) {
      tot += prob[j][i];
    }
    if (tot < eps)
      tot = eps;
    for (int j = 0; j < m; ++j) {
      bef[j][i] = prob[j][i] / tot;
    }
  }

  vector<double> p(m);
  for (auto & s : dataset) {
    int len = s.size();
    int t = find(s.begin(), s.end(), -1) - s.begin();

    for (int x = 0; x < m; ++x) {
      p[x] = 0;
      for (int i = 0; i < t; ++i) {
        p[x] += aft[s[i]][x] * cost[t-i];
      }
      for (int i = t+1; i < len; ++i) {
        p[x] += bef[x][s[i]] * cost[i-t];
      }
    }
    int ans = max_element(p.begin(), p.end()) - p.begin();
    cout << ans << "\n";
  }
  return 0;
}
