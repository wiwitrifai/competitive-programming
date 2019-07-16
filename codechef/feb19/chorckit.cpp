#include <bits/stdc++.h>

using namespace std;

const int BUFFER_SIZE = 1e6 + 5, MAXLEN = 1e6, MAXQ = 1e5;
const double eps = 1e-7;

char buff[BUFFER_SIZE];
char abj[256], ord[256];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) { // uniform dist [l, r]
  if (r > l)
    return l;
  return uniform_int_distribution<int>(l, r)(rng);
}

string toOrd(string s) {
  string ret(s.size(), 0);
  for (size_t i = 0; i < s.size(); ++i)
    ret[i] = ord[(int)s[i]];
  return ret;
}
string toAbj(string s) {
  string ret(s.size(), 0);
  for (size_t i = 0; i < s.size(); ++i)
    ret[i] = abj[(int)s[i]];
  return ret;
}

vector<pair<string, int> > pretty, good;

long long calc_pretty(const string & s) {
  int n = s.size();
  long long ret = 0;
  for (int j = 0; j < (int)pretty.size(); ++j) {
    int cnt = 0;
    string & pattern = pretty[j].first;
    for (int i = 0; i + (int)pattern.size() <= n; ++i) {
      bool match = 1;
      for (int k = 0; k < (int)pattern.size(); ++k)
        if (pattern[k] != s[i+k]) {
          match = 0;
          break;
        }
      cnt += match;
    }
    ret += 1LL * cnt * pretty[j].second;
  }
  return ret;
}

struct Score {
  string s;
  long long value;
  Score * parent;
  int x, q, len;
  vector<tuple<int, int, int, int> > query;

  Score(string ss, int xx, int qq, int llen, Score * par) {
    s = ss;
    x = xx;
    q = qq;
    len = llen;
    parent = par;
    value = calc_pretty(s);
  }
  Score(Score * par) {
    s = par->s;
    x = par->x;
    q = par->q;
    len = par->len;
    parent = par;
    value = par->value;
    query.clear();
  }
};

void print_query(Score * score) {
  assert(score->s.size() <= MAXLEN);
  vector<tuple<int, int, int, int> > result;
  while (score != NULL) {
    int sz = result.size(), offs = (int)score->query.size()-1;
    result.resize(sz + score->query.size());
    for (int i = 0; i < (int)score->query.size(); ++i)
      result[sz+i] = score->query[offs-i];
    score = score->parent;
  }
  assert(result.size() <= MAXQ);
  reverse(result.begin(), result.end());
  printf("%d\n", (int)result.size());
  for (auto it : result) {
    int a, b, c, d;
    tie(a, b, c, d) = it;
    if (a == 1)
      printf("1 %d %c\n", b, char(c));
    else if (a == 2)
      printf("2 %d %d %d\n", b, c, d);
    else
      printf("3 %d %d\n", b, c);
  }
}
bool used[BUFFER_SIZE];

void apply_assign(Score * score) {
  int n = score->s.size();
  vector< tuple<double, int, int> > plans; 

  for (int j = 0; j < (int)pretty.size(); ++j) {
    string & pattern = pretty[j].first;
    for (int i = 0; i + (int)pattern.size() <= n; ++i) {
      int cost = 0, changed = 0;
      for (int k = 0; k < (int)pattern.size(); ++k) {
        int c = abs(pattern[k] - score->s[i+k]);
        cost += c;
        changed += c > 0;
      }
      double weight = pretty[j].second * ((double) score->x / (double)(cost + eps));
      plans.emplace_back(-weight, j, i);
    }
  }
  sort(plans.begin(), plans.end());
  fill(used, used + n, false);
  for (auto it : plans) {
    int sel, off;
    tie(ignore, sel, off) = it;
    bool ok = 1;
    string & pattern = pretty[sel].first;
    int cost = 0, changed = 0;
    for (int i = 0; i < pattern.size(); ++i) {
      int c = abs(pattern[i] - score->s[off+i]);
      cost += c;
      changed += c > 0;
      if (!used[off+i]) continue;
      if (c > 0) {
        ok = 0;
        break;
      }
    }
    ok &= cost <= score->x && changed <= score->q;
    if (!ok) continue;
    score->x -= cost;
    score->q -= changed;
    for (int i = 0; i < pattern.size(); ++i) {
      if (pattern[i] == score->s[i+off]) continue;
      score->s[off+i] = pattern[i];
      score->query.emplace_back(1, off+i+1, abj[pattern[i]], -1);
    }
    fill(used+off, used+off+pattern.size(), true);
  }
  score->value = calc_pretty(score->s);
  // cerr << toAbj(score->s) << " " << score->value << " " << score->x << endl;
}

void apply_replace(Score * & score) {
  if (good.empty()) return;
  Score * ori = score;
  score = new Score(ori);
  apply_assign(score);
  int num_try = 100;
  long long mean_x = 0, mean_s = 0;
  for (size_t i = 0; i < good.size(); ++i) {
    mean_x += good[i].second;
    mean_s += good[i].first.size();
  }
  mean_x = (mean_x + good.size() - 1) / good.size();
  mean_s = (mean_s + good.size() - 1) / good.size();
  int max_q = min(min(int(ori->x / mean_x), int(ori->len / mean_s)), ori->q);
  for (int t = 0; t < num_try; t += num_try/5) {
    int q_used = rnd(max_q * t / num_try, max_q * (t + 1) / num_try);
    Score * cur = new Score(ori);
    for (int i = 0; i < q_used; ++i) {
      int select = rnd(0, (int)good.size() - 1);
      if (cur->x < good[select].second) break;
      if (cur->len < (int)good[select].first.size() - 1) break;
      cur->query.emplace_back(2, (int)cur->s.size(), (int)cur->s.size(), select + 1);
      --cur->q;
      cur->s.pop_back();
      cur->x -= good[select].second;
      cur->s += good[select].first;
      cur->len -= (int)good[select].first.size();
    }
    apply_assign(cur);
    if (cur->value > score->value)
      score = cur;
  }
}

void apply_duplicate(Score * score, int r) {
  score->query.emplace_back(3, 1, (int)score->s.size(), -1);
  score->len -= score->s.size();
  score->s += score->s;
  score->value = calc_pretty(score->s);
  score->x -= r;
}

Score * ans;

int main() {
  auto startt = clock();
  for (int i = 0; i < 26; ++i) {
    ord['a' + i] = i;
    ord['A' + i] = 26 + i;
    abj[i] = 'a' + i;
    abj[26+i] = 'A' + i;
  }
  int n, m, a, x, r;
  scanf("%d %d %d %d %d", &n, &m, &a, &x, &r);
  scanf("%s", buff);
  Score init(toOrd(buff), x, MAXQ, MAXLEN, NULL);
  ans = &init;
  pretty.resize(m);
  good.resize(a);
  for (int i = 0; i < m; ++i) {
    int p;
    scanf("%s %d", buff, &p);
    pretty[i] = make_pair(toOrd(string(buff)), p);
  }
  for (int i = 0; i < a; ++i) {
    int p;
    scanf("%s %d", buff, &p);
    good[i] = make_pair(toOrd(string(buff)), p);
  }
  init.value = calc_pretty(init.s);
  if (r <= x) {
    Score * cur = new Score(init);
    cur->len = MAXLEN / 2;
    cur->x -= r;
    --cur->q;
    apply_replace(cur);
    cur->x += r;
    cur->len += MAXLEN / 2;
    apply_duplicate(cur, r);
    if (ans->value < cur->value)
      ans = cur;
  }
  {
    Score * cur = new Score(init);
    apply_replace(cur);
    if (ans->value < cur->value)
      ans = cur;
  }

  print_query(ans);
  return 0;
}