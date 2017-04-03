#include <bits/stdc++.h>

using namespace std;
const double PI = acos(-1), eps = 1e-6;
typedef pair< double, double > point;
#define X first
#define Y second
double cross(point a, point b, point c) {
	double ax = a.first-b.first, ay = a.second-b.second, cx = c.first-b.first, cy = c.second-b.second;
	return ax * cy - cx * ay;
}

bool equals(double a, double b) {
	return fabs(a-b) < eps;
}

bool intersect(point a, point b, point c, point d, point & res) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	if (a > c) {
		swap(a, c);
		swap(b, d);
	}
	if (a.X >= d.X || c.X >= b.X)
		return false;
	// y = (yb-ya)/(xb-xa) * x + ya - m * xa
	// = (yb-ya) * (xxb-xxa) * x + ya * (xb-xa) * (xxb-xxa) - (yb-ya) * (xxb-xxa) * xa
	double  up1 = a.Y * (b.X-a.X) * (d.X-c.X) - (b.Y-a.Y) * (d.X-c.X) * a.X,
			    up2 = c.Y * (d.X-c.X) * (b.X-a.X) - (d.Y-c.Y) * (b.X-a.X) * c.X;
	double  down1 = (b.Y-a.Y) * (d.X-c.X),
					down2 = (d.Y-c.Y) * (b.X-a.X);
	if (equals(down1, down2))
		return false;
	double xx = (up1-up2)/(down2-down1);
	if (xx < max(a.first, c.first) || xx > min(b.first, d.first))
		return false;
	double yy = a.Y + (xx-a.X) * (b.Y-a.Y)/(b.X-a.X);
	res = point(xx, yy);
	return true;
}

class PolygonRotation {
public:
	double getVolume(vector <int> x, vector <int> y) {
		int n = x.size();
		vector< double > vy;
		for (int v : y)
			vy.push_back(v);
		for (int &v : x)
			v = abs(v);
		for (int i = 0; i + 1 < n; i++) {
			for (int j = i + 1; j < n; j++) {
				point res;
				if (intersect(point(x[i], y[i]), point(x[i+1], y[i+1]), point(x[j], y[j]), point(x[(j+1) % n], y[(j+1) % n]), res)) {
					vy.push_back(res.Y);
				}
			}
		}
		sort(vy.begin(), vy.end());
		vy.erase(unique(vy.begin(), vy.end()));
		vector< double > vx(vy.size(), 0);
		int id = 0;
		for (int i = 0; i < vy.size(); i++) {
			for (int j = 0; j < x.size(); j++) {
				int nx = (j + 1) % x.size();
				point a = make_pair(y[j], x[j]), b = make_pair(y[nx], x[nx]);
				if (a > b)
					swap(a, b);
				if (a.first <= vy[i] && vy[i] <= b.first) {
					if (a.first == b.first)
						vx[i] = max(vx[i], (double)max(abs(a.second), abs(b.second)));
					else
						vx[i] = max(vx[i], fabs(a.second + (double)(vy[i]-a.first) * (b.second - a.second)/(b.first-a.first)));
				}
			}
		}
		double ans = 0;
		for (int i = 0; i+1 < vy.size(); i++) {
			// (x-xa)/(xb-xa) = (y-ya)/(yb-ya)
			// x = (xb-xa)/(yb-ya) * y - m * ya + xa
			double m = (double)(vx[i+1]-vx[i]) / (double)(vy[i+1]-vy[i]);
			double c = vx[i] - m * vy[i];
			double a = m * m, b = 2 * m * c;
			c *= c;
			a /= 3, b /= 2;
			double yb = vy[i+1], ya = vy[i];
			ans += c * (yb-ya);
			yb *= vy[i+1], ya *= vy[i];
			ans += b * (yb-ya);
			yb *= vy[i+1], ya *= vy[i];
			ans += a * (yb-ya);
		}
		ans *= PI;
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
		cout << "Testing PolygonRotation (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491184218;
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
		PolygonRotation _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 1, 1, 0};
				int y[] = {1, 1, 0, 0};
				_expected = 3.141592653589793;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0, 1, 0, -1};
				int y[] = {2, 1, 0, 1};
				_expected = 2.0943951023931953;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0, 3, 0, -2, -2};
				int y[] = {2, 0, -3, -1, 1};
				_expected = 49.91641660703782;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0, 3, 3, 0, -1, -1};
				int y[] = {2, 2, -2, -2, -1, 1};
				_expected = 113.09733552923255;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
