#include <bits/stdc++.h>

using namespace std;

#define MAXX 1001

int A, B;

int right(int x1, int y1, int x2, int y2)
{
  return x1*y2-x2*y1 >= 0;
}

int cmp(const pair<int,int> &p, const pair<int,int> &q)
{
  return !right(p.first-A, p.second-B, q.first-A, q.second-B);

}
int main()
{
  int N;
  scanf("%d", &N);
  scanf("%d%d", &A, &B);
  int best = 0, worst = 1;
  int above = 0, below = 0;
  vector<pair<int,int>> v;
  for (int i = 1; i < N; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    v.push_back(make_pair(a,b));
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); ++i) {
    printf("%d %d\n", v[i].first, v[i].second);
  }
  printf("%d %d\n", best+1, worst);
  return 0;
}