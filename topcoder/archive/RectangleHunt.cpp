#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
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
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
};

vector<point> vp;

double check(point a, point b, point c, point d) {
	point ab = b - a, cd = d - c;
	if (!(ab == cd)) {
		swap(c, d);
		cd = cd * -1;
	}
	if (!(ab == cd))
		return -1;
	point ac = c-a, bd = d-b;
	if (!(ac == bd))
		return -1;
	if (!eq((ab * ac), 0))
		return -1;
	return abs(ab % ac);
}


class RectangleHunt {
public:
	double largest(vector <int> x, vector <int> y) {
		int n = x.size();
		vp.resize(n);
		for (int i = 0; i < n; ++i)
			vp[i] = point(x[i], y[i]);
		double ans = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int a = j + 1; a < n; ++a) {
					for (int b = a + 1; b < n; ++b) {
						ans = max(ans, check(vp[i], vp[j], vp[a], vp[b]));
						ans = max(ans, check(vp[i], vp[a], vp[j], vp[b]));
					}
				}
			}
		}

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
		cout << "Testing RectangleHunt (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1565454207;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RectangleHunt _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 1, 0, 1};
				int y[] = {0, 2, 2, 0};
				_expected = 2.0;
				_received = _obj.largest(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0, 1, 0, 1};
				int y[] = {0, 2, 2, 3};
				_expected = -1.0;
				_received = _obj.largest(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0, 5, 6, 11};
				int y[] = {5, 2, 15, 12};
				_expected = 68.0;
				_received = _obj.largest(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0, 3, 5, 8};
				int y[] = {0, 4, 1, 5};
				_expected = -1.0;
				_received = _obj.largest(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				// int x[] = {0, 3, -4, -1};
				// int y[] = {0, 4, 3, 7};
				int x[] = {4, 7, 0, 3};
				int y[] = {4, 8, 7, 11};
				_expected = 25;
				_received = _obj.largest(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.largest(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
