#include <bits/stdc++.h>

using namespace std;

typedef long long LD;

inline bool eq(LD a, LD b) { return a == b; }
inline bool lt(LD a, LD b) { return a < b; }
inline bool le(LD a, LD b) { return a <= b; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

const long long mod = 998244353;

class Subpolygon {
public:
	int sumOfAreas(int n) {
		vector<point> vp;
		vp.push_back(point(0, n));
		for (int i = 1; i < n; ++i) {
			vp.push_back(point(-i, n-i));
		}
		vp.push_back(point(-n, 0));
		for (int i = 1; i < n; ++i) {
			vp.push_back(point(-(n-i), -i));
		}
		vp.push_back(point(0, -n));
		for (int i = 1; i < n; ++i) {
			vp.push_back(point(i, -(n-i)));	
		}
		vp.push_back(point(n, 0));
		for (int i = 1; i < n; ++i) {
			vp.push_back(point((n-i), i));
		}
		vector<point> pol;
		point p(0, 0);
		for (point q : vp) {
			p = p + q;
			p.x %= mod;
			p.y %= mod;
			pol.push_back(p);
		}
		int sz = pol.size();
		for (int i = 0; i < sz; ++i)
			pol.push_back(pol[i]);
		long long xx = 0, yy = 0;
		long long ans =0;
		long long pp = 1;
		for (int i = 0; i < sz; ++i)
			pp = (pp * 2) % mod;
		for (int i = 0; i < 2 * sz; ++i) {
			xx = (xx * 2 + pol[i].x) % mod;
			yy = (yy * 2 + pol[i].y) % mod;
			if (i >= sz) {
				xx = (xx - pol[i-sz].x * pp) % mod;
				yy = (yy - pol[i-sz].y * pp) % mod;
				if (xx < 0) xx += mod;
				if (yy < 0) yy += mod;
				ans = (ans + pol[i].x * yy - pol[i].y * xx) % mod;
			}
		}
		long long inv2 = (mod + 1) / 2;
		ans = (ans * inv2) % mod;
		ans = (ans * inv2) % mod;
		if (ans < 0) ans += mod;
		return ans;
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
		cout << "Testing Subpolygon (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1534348031;
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
		Subpolygon _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				_expected = 3;
				_received = _obj.sumOfAreas(n); break;
			}
			case 1:
			{
				int n = 2;
				_expected = 1650;
				_received = _obj.sumOfAreas(n); break;
			}
			case 2:
			{
				int n = 35;
				_expected = 132946800;
				_received = _obj.sumOfAreas(n); break;
			}
			case 3:
			{
				int n = 125000;
				_expected = 0;
				_received = _obj.sumOfAreas(n); break;
			}
			/*case 4:
			{
				int n = ;
				_expected = ;
				_received = _obj.sumOfAreas(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.sumOfAreas(n); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
