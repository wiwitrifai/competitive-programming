#include <bits/stdc++.h>

using namespace std;

const int  N = 1e5 + 6;

int x[N], y[N];

long long calc(long long a, long long b, long long xmin, long long xmax) {
  long long x = a <= 0 ? xmin : xmax;
  return x * a + b;
}
long long a = 0, b = 0;
set<pair<int, int> > kanandekat, kananlewat;
set<pair<int, int> > kirijauh;
long long ans = 1e18;
int now = 0;

void pindah() {
  auto kl = kananlewat.begin();
  // cerr << " pindah " << kl->second << endl;
  int nxt = max(now, kl->first);
  assert(now <= kl->first);
  ans = min(ans, calc(a, b, now, nxt));
  b -= x[kl->second] + y[kl->second];
  kirijauh.insert(make_pair(y[kl->second] - x[kl->second], kl->second));
  b += - x[kl->second] + y[kl->second];
  kananlewat.erase(kl);
  a += 2;
  now = nxt;
  ans = min(ans, calc(a, b, now, now));
}

void tambahkiri(int rig) {
  auto kj = --kirijauh.end();
  if (kj->first > y[rig] - x[rig]) {
    // cerr << " tambah kiri " << rig << endl;
    b -= kj->first;
    kirijauh.erase(kj);
    b += y[rig] - x[rig];
    kirijauh.insert(make_pair(y[rig] - x[rig], rig));
    ans = min(ans, calc(a, b, now, now));
  }
}

void tambahkanan(int id, int meet) {
  if (x[id] <= now) {
    tambahkiri(id);
    return;
  }
  // cerr << " tambah kanan " << id << endl;
  meet = max(now, meet);
  ans = min(ans, calc(a, b, now, meet));
  auto kj = --kirijauh.end();
  if (kj->first <= y[id] - x[id]) return;
  b -= kj->first;
  b += y[id] + x[id];
  a -= 2;
  kirijauh.erase(kj);
  kananlewat.insert(make_pair(x[id], id));
  now = meet;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", x+i, y+i);
  }

  for (int i = 0; i < n; ++i) {
    kanandekat.insert(make_pair(x[i] + y[i], i));
  }
  a = b = 0;
  while (kirijauh.size() + kananlewat.size() < k) {
    auto it = kanandekat.begin();
    pair<int, int> val = *it;
    kanandekat.erase(it);
    // cerr << " add " << val.second << endl;
    --a;
    b += x[val.second] + y[val.second];
    kananlewat.insert(make_pair(x[val.second], val.second));
  }
  int now = 0;
  while (kanandekat.size() > 0) {
    auto it = kanandekat.begin();
    int rig = it->second;
    kanandekat.erase(it);
    if (x[rig] <= now) {
      if (kirijauh.empty()) continue;
      tambahkiri(rig);
      continue;
    }
    else {
      while (kirijauh.empty()) {
        pindah();
      }
      auto kj = --kirijauh.end();
      int meet = (max(x[rig] + y[rig] - kj->first, 0)) / 2;
      if (meet > x[rig]) continue;
      meet = max(meet, now);
      while (kananlewat.size() > 0 && meet >= kananlewat.begin()->first) {
        pindah();
      }
      tambahkanan(rig, meet);
    }
  }
  while (kananlewat.size() > 0) {
    pindah();
  }
  printf("%lld\n", ans);
  return 0;
}