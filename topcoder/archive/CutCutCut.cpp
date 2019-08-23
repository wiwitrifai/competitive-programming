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
ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

bool intersect(point a, point b, point c, point d) {
	return (ccw(a, b, c) * ccw(a, b, d)) < 0;
}

class CutCutCut {
public:
	vector <int> findPieces(vector <int> X1, vector <int> Y1, vector <int> X2, vector <int> Y2, int Q) {
		vector<pair<point, point>> vp;
		vector<int> ans;
		int cnt = 1;
		for (int i = 0; i < Q; ++i) {
			point a(X1[i], Y1[i]);
			point b(X2[i], Y2[i]);
			++cnt;
			for (auto it : vp) {
				cnt += intersect(it.first, it.second, a, b);
			}
			vp.emplace_back(a, b);
			ans.push_back(cnt);
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
		cout << "Testing CutCutCut (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1563375661;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CutCutCut _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X1[] = {1, 2, 3};
				int Y1[] = {0, 0, 0};
				int X2[] = {1, 2, 3};
				int Y2[] = {10000, 10000, 10000};
				int Q = 3;
				int __expected[] = {2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPieces(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int)), Q); break;
			}
			case 1:
			{
				int X1[] = {0, 5000};
				int Y1[] = {5000, 10000};
				int X2[] = {10000, 5000};
				int Y2[] = {5000, 0};
				int Q = 2;
				int __expected[] = {2, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPieces(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int)), Q); break;
			}
			case 2:
			{
				int X1[] = {1,0,3,9997};
				int Y1[] = {0,1,0,10000};
				int X2[] = {1,10000,0,10000};
				int Y2[] = {10000,1,3,9997};
				int Q = 4;
				int __expected[] = {2, 4, 7, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPieces(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int)), Q); break;
			}
			/*case 3:
			{
				int X1[] = ;
				int Y1[] = ;
				int X2[] = ;
				int Y2[] = ;
				int Q = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPieces(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int)), Q); break;
			}*/
			/*case 4:
			{
				int X1[] = ;
				int Y1[] = ;
				int X2[] = ;
				int Y2[] = ;
				int Q = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPieces(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int)), Q); break;
			}*/
			/*case 5:
			{
				int X1[] = ;
				int Y1[] = ;
				int X2[] = ;
				int Y2[] = ;
				int Q = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPieces(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int)), Q); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
