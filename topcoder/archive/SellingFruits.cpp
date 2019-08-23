#include <bits/stdc++.h>

using namespace std;

class SellingFruits {
public:
	int maxDays(int x, int f, int d, int p) {
		long long day = (long long)x + (long long)p;
		long long tot = 1LL * f * p + d;
		long long r = tot/day, l = 0;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			long long uang = d - 1LL * max(mid-f, 0) * p;
			if (uang >= 1LL * x * mid)
				l = mid;
			else
				r = mid-1;
		}
		return l;
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
		cout << "Testing SellingFruits (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486948110;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SellingFruits _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 3;
				int f = 5;
				int d = 100;
				int p = 10;
				_expected = 11;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			case 1:
			{
				int x = 2;
				int f = 17;
				int d = 20;
				int p = 1;
				_expected = 10;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			case 2:
			{
				int x = 1;
				int f = 97;
				int d = 98;
				int p = 1;
				_expected = 97;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			case 3:
			{
				int x = 16;
				int f = 4;
				int d = 8;
				int p = 2;
				_expected = 0;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			case 4:
			{
				int x = 17;
				int f = 1;
				int d = 2000000000;
				int p = 4;
				_expected = 95238095;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			case 5:
			{
				int x = 1;
				int f = 1996245611;
				int d = 1999990159;
				int p = 123;
				_expected = 1996275808;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			case 6:
			{
				int x = 15000000;
				int f = 100;
				int d = 2000000000;
				int p = 1;
				_expected = 133;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			case 7:
			{
				int x = 1;
				int f = 1000000000;
				int d = 2000000000;
				int p = 1000000000;
				_expected = 1000000000;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			case 8:
			{
				int x = 2000000000;
				int f = 1;
				int d = 2000000000;
				int p = 2000000000;
				_expected = 1;
				_received = _obj.maxDays(x, f, d, p); break;
			}
			/*case 9:
			{
				int x = ;
				int f = ;
				int d = ;
				int p = ;
				_expected = ;
				_received = _obj.maxDays(x, f, d, p); break;
			}*/
			/*case 10:
			{
				int x = ;
				int f = ;
				int d = ;
				int p = ;
				_expected = ;
				_received = _obj.maxDays(x, f, d, p); break;
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
