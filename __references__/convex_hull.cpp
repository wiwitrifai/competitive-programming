typedef pair<long long,long long> point;
#define x first
#define y second
// (p-q) x (r-q)
long long cross(point p, point q, point r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

bool collinear(point a, point o, point b) {
    return cross(a, o, b) == 0;
}

// true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(p, q, r) > 0;
}

point pivot;

long long dist2(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(point a, point b) {
    if(collinear(pivot, a, b)) {
     return dist2(a, pivot) < dist2(b, pivot);
    }
    return ccw(pivot, a, b);
}

bool cmp(point a, point b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

// P tidak siklik, P[0] tidak mengulang di P.back()
// return convex hull siklik, P[0] mengulang di P.back()
vector<point> ConvexHull(vector<point> P) {
  int i, j, n = (int) P.size();
  if(n < 3)
    return P;
  int PO = 0;
  for(i = 1; i < n; i++) {
  if(cmp(P[P0], P[P[i]])) {
      PO = i;
  }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  if(collinear(P.back(), P[0], P[1])) {
    vector< point > S;
    S.push_back(P[0]);
    S.push_back(P.back());
    return S;
  }
  sort(++P.begin(), P.end(), angle_cmp);
  int k = P.size() - 1;
  while(k && collinear(P[0], P[k-1], P[k])) k--;
  reverse(P.begin() + k, P.end());
  vector<point> S;
  S.push_back(P[n-1]);
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
  j = (int) S.size() - 1;
  if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
  else S.pop_back();
  }
  S.pop_back();
  return S;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  vector<point> p;
  for(int i = 0; i < n; i++) {
  int a, b;
  scanf("%d %d", &a, &b);
  p.push_back(point(a, b));
  }
  vector<point> ch = ConvexHull(p);
  cout << ch.size() << endl;
  for(auto it : ch) {
  printf("%I64d %I64d\n", it.x, it.y);
  }
    return 0;
}