#include <bits/stdc++.h>

using namespace std;

const int ITER = 1000;

typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y, z;
  point(LD x = 0, LD y = 0, LD z = 0) : x(x), y(y), z(z) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y, z+p.z); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y, z-p.z); }
  point operator*(LD s) { return point(x*s, y*s, z*s); }
  point operator/(LD s) { return point(x/s, y/s, z/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y + z*p.z; } // dot
  // LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y) && eq(z, p.z); }
  // bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
LD dist(point a, point b) { return (b-a).norm_sq(); }

struct line {
  point a, ab; // p(t) = a + ab * t
  line(point ta = point(), point tb = point()) {
    // if (tb < ta) swap(ta, tb);
    a = ta; ab = tb-ta;
  }
  point b() { return a + ab; }
  bool isLine() { return !(ab == point()); } // minor
  operator bool() { return !(ab == point()); } // minor
  point get(LD s) {
  	return a + ab * s;
  }
};

line l1, l2;
point t;
LD solve2(point p) {
	line mid = line((p + l2.a) * 0.5, (p + l2.b()) * 0.5);
	LD lo = -1e13, hi = 1e13;
	LD ans = dist(mid.a, t);
	for (int i = 0; i < ITER; ++i) {
		double le = (lo + lo + hi) / 3, ri = (lo + hi + hi) / 3;
		point p1 = mid.get(le), p2 = mid.get(ri);
		LD d1 = dist(p1, t), d2 = dist(p2, t);
		ans = min(ans, min(d1, d2));
		if (d1 < d2)
			hi = ri;
		else
			lo = le;
	}
	return ans;
}

double solve() {
	double lo = -1e13, hi = 1e13;
	LD ans = solve2(l1.a);
	for (int i = 0; i < ITER; ++i) {
		double le = (lo + lo + hi) / 3, ri = (lo + hi + hi) / 3;
		point p1 = l1.get(le), p2 = l1.get(ri);
		LD d1 = solve2(p1), d2 = solve2(p2);
		ans = min(ans, min(d1, d2));
		if (d1 < d2)
			hi = ri;
		else
			lo = le;
	}
	cerr << lo << " " << hi << endl;
	cerr << setprecision(20) << fixed;
	cerr << hi - lo << endl;
	return ans;
}

class SpaceProbes {
public:
	double focusDistance(vector<long long> x, vector<long long> y, vector<long long> z) {
		vector<point> vp(5);
		for (int i = 0; i < 5; ++i)
			vp[i] = point(x[i], y[i], z[i]);
		l1 = line(vp[0], vp[1]);
		l2 = line(vp[2], vp[3]);
		t = vp[4];
		return sqrt(solve());
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing SpaceProbes (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1547574392;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SpaceProbes _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long x[] = {0,1,2,3,4};
				long long y[] = {5,6,7,8,9};
				long long z[] = {12,6,4,2,5};
				_expected = 0.0;
				_received = _obj.focusDistance(vector<long long>(x, x+sizeof(x)/sizeof(long long)), vector<long long>(y, y+sizeof(y)/sizeof(long long)), vector<long long>(z, z+sizeof(z)/sizeof(long long))); break;
			}
			case 1:
			{
				long long x[] = {2,6,4,5,5};
				long long y[] = {-1,7,7,4,7};
				long long z[] = {8,8,2,4,2};
				_expected = 2.23606797749979;
				_received = _obj.focusDistance(vector<long long>(x, x+sizeof(x)/sizeof(long long)), vector<long long>(y, y+sizeof(y)/sizeof(long long)), vector<long long>(z, z+sizeof(z)/sizeof(long long))); break;
			}
			case 2:
			{
				long long x[] = {0,-2,1,4,0};
				long long y[] = {-1,-999999999998,1,999999999997,0};
				long long z[] = {-1,1000000000000,1,-999999999998,-2};
				_expected = 0.8660254037861707;
				_received = _obj.focusDistance(vector<long long>(x, x+sizeof(x)/sizeof(long long)), vector<long long>(y, y+sizeof(y)/sizeof(long long)), vector<long long>(z, z+sizeof(z)/sizeof(long long))); break;
			}
			case 3:
			{

				long long x[] = {-1000000000000LL,1000000000000LL,-1000000000000LL,1000000000000LL,-1000000000000LL};
				long long y[] = {1000000000000LL,-1000000000000LL,-1000000000000LL,1000000000000LL,1000000000000LL};
				long long z[] = {-1000000000000LL,-1000000000000LL,1000000000000LL,-1000000000000LL,1000000000000LL};
				_expected = 0;
				_received = _obj.focusDistance(vector<long long>(x, x+sizeof(x)/sizeof(long long)), vector<long long>(y, y+sizeof(y)/sizeof(long long)), vector<long long>(z, z+sizeof(z)/sizeof(long long))); break;
			}
			/*case 4:
			{
				long long x[] = ;
				long long y[] = ;
				long long z[] = ;
				_expected = ;
				_received = _obj.focusDistance(vector<long long>(x, x+sizeof(x)/sizeof(long long)), vector<long long>(y, y+sizeof(y)/sizeof(long long)), vector<long long>(z, z+sizeof(z)/sizeof(long long))); break;
			}*/
			/*case 5:
			{
				long long x[] = ;
				long long y[] = ;
				long long z[] = ;
				_expected = ;
				_received = _obj.focusDistance(vector<long long>(x, x+sizeof(x)/sizeof(long long)), vector<long long>(y, y+sizeof(y)/sizeof(long long)), vector<long long>(z, z+sizeof(z)/sizeof(long long))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
