#include "mining.h"
#include <bits/stdc++.h>
using namespace std;


const long long N = 2e6 + 6, M = 1001;

bool sq[N];
bool cek[M][M];

vector<pair<int, int> > cand;
int calc(int x, int y) {
  int cnt1 = 0, cnt2 = 0;
  for (auto it : cand) {
    int dx = abs(it.first - x), dy = abs(it.second - y);
    if (cek[dx][dy]) ++cnt1;
    else ++cnt2;
  }
  return min(cnt1, cnt2);
}

map<pair<int, int>, int> mp;
int mIsIntegerDistance(int x, int y) {
  pair<int, int> p(x, y);
  if (!mp.count(p)) {
    mp[p] = isIntegerDistance(x, y);
  }
  return mp[p];
}

bool rused[M], cused[M];

void findGold() {
  srand(time(0));
  for (int i = 0; i * i < N; ++i) {
    sq[i * i] = 1;
  }
  for (int i = 0; i < M; ++i)
    for (int j = 0; j < M; ++j)
      cek[i][j] = sq[i * i + j * j];
  vector<pair<int, int> > tanya;
  for (int i = 1; i < 1000; i += 2) {
    tanya.emplace_back(i, i);
  }
  for (int i = 2; i < 1000; i += 2) {
    tanya.emplace_back(i, 1000-i);
  }
  pair<int, int> cur(-1, -1);
  bool found = 0;
  random_shuffle(tanya.begin(), tanya.end());
  for (auto it : tanya) {
    int res = mIsIntegerDistance(it.first, it.second);
    if (res) {
      found = 1;
      cur = it;
      break;
    }
  }
  if (!found) {
    answer(1000, 1000);
    return;
  }
  cand.clear();
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= 1000; ++j) {
      if (cek[abs(i-cur.first)][abs(j-cur.second)])
        cand.emplace_back(i, j);
    }
  }
  while (cand.size() > 1) {
    int r = rand() % tanya.size();
    int bx = tanya[r].first, by = tanya[r].second, best = calc(bx, by);
    for (int i = 0; i < tanya.size(); ++i) {
      if (i == r) continue;
      int v = calc(tanya[i].first, tanya[i].second);
      if (v > best) {
        bx = tanya[i].first, by = tanya[i].second;
        best = v;
      }
    }
    if (best == 0) {
      r = rand() % cand.size();
      int x = cand[r].first, y = cand[r].second;
      for (int i = 1; i <= 1000; ++i) {
        if (i == y) continue;
        int v = calc(x, i);
        if (v > best) {
          bx = x, by = i;
          best = v;
        }
      }
      for (int i = 1; i <= 1000; ++i) {
        if (i == x) continue;
        int v = calc(i, y);
        if (v > best) {
          bx = i, by = y;
          best = v;
        }
      }
    }
    bool res = mIsIntegerDistance(bx, by);
    vector<pair<int, int> > to;
    for (auto it : cand) {
      int dx = abs(it.first - bx), dy = abs(it.second - by);
      if (cek[dx][dy] == res)
        to.push_back(it);
    }
    cand.swap(to);
  }
  answer(cand[0].first, cand[0].second);
}
