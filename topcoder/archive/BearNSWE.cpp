#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int to[256];
class BearNSWE {
public:
	double totalDistance(vector <int> a, string dir) {
		string str = "NWSE";
		for (int i = 0; i < 4; i++)
			to[str[i]] = i;
		int n = a.size();
		double ans = 0;
		int x, y;
		x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			ans += a[i];
			x += a[i] * dx[to[dir[i]]];
			y += a[i] * dy[to[dir[i]]];
		}
		ans += sqrt(x * x + y * y);
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
		cout << "Testing BearNSWE (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487549950;
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
		BearNSWE _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,3,3};
				string dir = "NES";
				_expected = 10.60555127546399;
				_received = _obj.totalDistance(vector <int>(a, a+sizeof(a)/sizeof(int)), dir); break;
			}
			case 1:
			{
				int a[] = {10,10,10,10};
				string dir = "NWSE";
				_expected = 40.0;
				_received = _obj.totalDistance(vector <int>(a, a+sizeof(a)/sizeof(int)), dir); break;
			}
			case 2:
			{
				int a[] = {10,10,10,15,8,20,5};
				string dir = "NEWEWWE";
				_expected = 90.8062484748657;
				_received = _obj.totalDistance(vector <int>(a, a+sizeof(a)/sizeof(int)), dir); break;
			}
			case 3:
			{
				int a[] = {42};
				string dir = "E";
				_expected = 84.0;
				_received = _obj.totalDistance(vector <int>(a, a+sizeof(a)/sizeof(int)), dir); break;
			}
			case 4:
			{
				int a[] = {10,40,40};
				string dir = "NSE";
				_expected = 140.0;
				_received = _obj.totalDistance(vector <int>(a, a+sizeof(a)/sizeof(int)), dir); break;
			}
			/*case 5:
			{
				int a[] = ;
				string dir = ;
				_expected = ;
				_received = _obj.totalDistance(vector <int>(a, a+sizeof(a)/sizeof(int)), dir); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				string dir = ;
				_expected = ;
				_received = _obj.totalDistance(vector <int>(a, a+sizeof(a)/sizeof(int)), dir); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				string dir = ;
				_expected = ;
				_received = _obj.totalDistance(vector <int>(a, a+sizeof(a)/sizeof(int)), dir); break;
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
